#pragma once
#include <gl2d/gl2d.h>


struct Bullet
{
	glm::vec2 position = { 1.0f, 1.0f };
	glm::vec2 fireDirection = { 1.0f, 1.0f };

	void render(gl2d::Renderer2D &renderer,
		gl2d::Texture bulletsTexture, gl2d::TextureAtlasPadding bulletsAtlas
	);

	void update(float deltaTime);
};