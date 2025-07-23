#define GLM_ENABLE_EXPERIMENTAL
#include "gameLayer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "platformInput.h"
#include "imgui.h"
#include <iostream>
#include <sstream>
#include "imfilebrowser.h"
#include <gl2d/gl2d.h>
#include <tiledRenderer.h>
#include <bullet.h>
#include <vector>


struct GameData
{
	glm::vec2 playerPos = {100,100};
	std::vector<Bullet> bullets;

}gameData;



gl2d::Renderer2D renderer;

constexpr int BACKGROUNDS = 4;

//SPACE SHIPS TEXTURES
gl2d::Texture spaceShipsTexture;
gl2d::TextureAtlasPadding spaceShipsAtlas;

//LOAD BULLET TEXTURES
gl2d::Texture bulletsTexture;
gl2d::TextureAtlasPadding bulletsAtlas;

//gl2d::Texture mira;
gl2d::Texture background[BACKGROUNDS];
TiledRenderer tileRenderer[BACKGROUNDS];

TiledRenderer tiledRenderer[BACKGROUNDS];



bool initGame()
{
	//initializing stuff for the renderer
	gl2d::init();
	renderer.create();

	//LOAD THE ATLAS WITH PIXEL PADDING
	spaceShipsTexture.loadFromFileWithPixelPadding
	(RESOURCES_PATH "spaceships.png", 128, true);
	spaceShipsAtlas = gl2d::TextureAtlasPadding(5, 2, spaceShipsTexture.GetSize().x, spaceShipsTexture.GetSize().y);

	//LOAD THE BULLET ATLAS WITH PIXEL PADDING
	bulletsTexture.loadFromFileWithPixelPadding
	(RESOURCES_PATH "projectiles.png", 500, true);
	bulletsAtlas = gl2d::TextureAtlasPadding(3, 2, bulletsTexture.GetSize().x, bulletsTexture.GetSize().y);

	//loading the saved data. Loading an entire structure like this makes savind game data very easy.
	platform::readEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));


	//load character from file
	//mira.loadFromFile(RESOURCES_PATH "SpaceShip.png", true);

	//load backgroundS from file
	background[0].loadFromFile(RESOURCES_PATH "Backgrounds/Background_Nebulae.png", true);
	background[1].loadFromFile(RESOURCES_PATH "Backgrounds/Background_Dust.png", true);
	background[2].loadFromFile(RESOURCES_PATH "Backgrounds/Background_Stars.png", true);
	background[3].loadFromFile(RESOURCES_PATH "Backgrounds/Background_Planets.png", true);

	//Render backgrounds 
	tiledRenderer[0].texture = background[0];
	tiledRenderer[1].texture = background[1];
	tiledRenderer[2].texture = background[2];
	tiledRenderer[3].texture = background[3];


	//LOAD PARALAX EFFECT
	tiledRenderer[0].paralaxStrength = 0;
	tiledRenderer[1].paralaxStrength = 0.4;
	tiledRenderer[2].paralaxStrength = 0.7;
	tiledRenderer[3].paralaxStrength = 1;

	

	return true;
}



bool gameLogic(float deltaTime)
{
#pragma region init stuff
	int w = 0; int h = 0;
	w = platform::getFrameBufferSizeX(); //window w
	h = platform::getFrameBufferSizeY(); //window h
	
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer.updateWindowMetrics(w, h);
#pragma endregion


#pragma region render background
	
	

	//ZOOM CAMERA
	renderer.currentCamera.zoom = 0.5;

	for (int i = 0; i< BACKGROUNDS; i++)
	{
		tiledRenderer[i].render(renderer);
	}

	
	
#pragma endregion


#pragma region movement
	glm::vec2 move = {};

	if (
		platform::isButtonHeld(platform::Button::W) ||
		platform::isButtonHeld(platform::Button::Up)
		)
	{
		move.y = -1;
	}
	if (
		platform::isButtonHeld(platform::Button::S) ||
		platform::isButtonHeld(platform::Button::Down)
		)
	{
		move.y = 1;
	}
	if (
		platform::isButtonHeld(platform::Button::A) ||
		platform::isButtonHeld(platform::Button::Left)
		)
	{
		move.x = -1;
	}
	if (
		platform::isButtonHeld(platform::Button::D) ||
		platform::isButtonHeld(platform::Button::Right)
		)
	{
		move.x = 1;
	}

	if (move.x != 0 || move.y != 0)
	{
		move = glm::normalize(move);
		move *= deltaTime * 200; //200 pixels per second
		gameData.playerPos += move;
	}
#pragma endregion


#pragma region Follow

	//CAMERA FOLLOW PLAYER
	renderer.currentCamera.follow(gameData.playerPos, deltaTime * 550, 1, 200, w, h);

#pragma	endregion	
	

#pragma region mouse pos 

	glm::vec2 mousePos = platform::getRelMousePosition();
	glm::vec2 screenCenter(w / 2.f, h / 2.f);

	glm::vec2 mouseDirection = mousePos - screenCenter;

	if (glm::length(mouseDirection) == 0.f)
	{
		mouseDirection = { 1,0 };
	}
	else
	{
		mouseDirection = normalize(mouseDirection);
	}

	float spaceShipAngle = atan2(mouseDirection.y, -mouseDirection.x);

#pragma endregion

	
#pragma region handle bullets


	if (platform::isLMousePressed())
	{
		Bullet b;

		b.position = gameData.playerPos;
		b.fireDirection = mouseDirection;

		gameData.bullets.push_back(b);
	}


	for (int i = 0; i < gameData.bullets.size(); i++)
	{

		if (glm::distance(gameData.bullets[i].position, gameData.playerPos) > 5'000)
		{
			gameData.bullets.erase(gameData.bullets.begin() + i);
			i--;
			continue;
		}

		gameData.bullets[i].update(deltaTime);

	}
#pragma endregion


#pragma region render ship
	constexpr float shipSize = 250.f;

	renderer.renderRectangle({ gameData.playerPos - glm::vec2(shipSize / 2,shipSize / 2)
		, shipSize,shipSize }, spaceShipsTexture,
		Colors_White, {}, glm::degrees(spaceShipAngle) + 90.f, spaceShipsAtlas.get(3,0));
#pragma endregion

#pragma region render bullets

	for (auto& b : gameData.bullets)
	{
		b.render(renderer, bulletsTexture, bulletsAtlas);
	}

#pragma endregion



	renderer.flush();
	//ImGui::ShowDemoWindow();

	

	ImGui::Begin("debug");

	ImGui::Text("Bullets count: %d", (int)gameData.bullets.size());

	ImGui::End();

	return true;

}



//This function might not be be called if the program is forced closed
void closeGame()
{

	//saved the data.
	//platform::writeEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

}
