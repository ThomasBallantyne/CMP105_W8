#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include "Ball.h"
#include "Framework/Collision.h"
#include "Paddle.h"
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	bool area1;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::Font font;
	Ball ball;
	Paddle player1;
	Paddle player2;
	sf::Vertex line[2];
	sf::Text score1;
	sf::Text score2;
};