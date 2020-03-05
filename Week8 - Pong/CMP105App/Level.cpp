#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	area1 = false;

	// initialise game objects
	player1.setSize(sf::Vector2f(50, 150));
	player1.setPosition(25, 275);
	player1.setFillColor(sf::Color::Blue);
	player1.setInput(input);

	player2.setSize(sf::Vector2f(50, 150));
	player2.setPosition(1125, 275);
	player2.setFillColor(sf::Color::Red);
	player2.setInput(input);

	ball.setSize(sf::Vector2f(25, 25));
	ball.setPosition(625, 50);
	ball.setFillColor(sf::Color::Red)
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player1.handleInput(dt);
	player2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player1.update(dt);
	player2.update(dt);
	ball.update(dt);
	if (area1)
	{
		if (Collision::checkBoundingBox(&ball, &player1))
		{
			ball.collisionResponse(1);
		}
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(player1);
	window->draw(player2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}