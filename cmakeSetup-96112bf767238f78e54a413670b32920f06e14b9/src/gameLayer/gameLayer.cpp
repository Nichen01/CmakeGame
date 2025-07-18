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

//testing github
struct GameData
{
	glm::vec2 playerPos = {100,100};

}gameData;

gl2d::Renderer2D renderer;
gl2d::Texture mira;
gl2d::Texture background;

TiledRenderer tiledRenderer;

bool initGame()
{
	//initializing stuff for the renderer
	gl2d::init();
	renderer.create();

	//loading the saved data. Loading an entire structure like this makes savind game data very easy.
	platform::readEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));


	//load character from file
	mira.loadFromFile(RESOURCES_PATH "mira.jpg", true);
	//load background from file5
	background.loadFromFile(RESOURCES_PATH "Backgrounds/SpaceBackground.png", true);
	
	tiledRenderer.texture = background;

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


#pragma region render background
	tiledRenderer.render(renderer);
	renderer.currentCamera.follow(gameData.playerPos, deltaTime * 200, 10, 200, w, h);
	renderer.currentCamera.zoom = 2;
	renderer.renderRectangle({ 0,0,1000,1000 }, background);
#pragma endregion

	renderer.renderRectangle({ gameData.playerPos, 200, 200 }, mira);
	

#pragma region movement1
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


	gameData.playerPos = glm::clamp(gameData.playerPos, glm::vec2{0,0}, glm::vec2{w - 100,h - 100});
	renderer.flush();


	//ImGui::ShowDemoWindow();
	return true;
#pragma endregion

}

//This function might not be be called if the program is forced closed
void closeGame()
{

	//saved the data.
	platform::writeEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

}
