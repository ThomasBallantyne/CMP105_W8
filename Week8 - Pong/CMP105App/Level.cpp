#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	area1 = false;
	window->setMouseCursorVisible(false);

	font.loadFromFile("font/Orbitron-VariableFont_wght.ttf");

	// initialise game objects
	player1.setSize(sf::Vector2f(50, 150));
	player1.setCollisionBox(0, 0, 50, 150);
	player1.setPosition(25, 275);
	player1.setFillColor(sf::Color::Blue);
	player1.setInput(input);
	player1.setControlType(1);

	player2.setSize(sf::Vector2f(50, 150));
	player2.setCollisionBox(0, 0, 50, 150);
	player2.setPosition(1125, 400);
	player2.setFillColor(sf::Color::Red);
	player2.setInput(input);

	ball.setSize(sf::Vector2f(25, 25));
	ball.setCollisionBox(0, 0, 25, 25);
	ball.setPosition(625, 50);
	ball.setFillColor(sf::Color::Red);

	line[0].color = sf::Color::Blue;
	line[0].position = sf::Vector2f(600, 0);
	line[1].color = sf::Color::Red;
	line[1].position = sf::Vector2f(600, 675);

	score1.setFont(font);
	score1.setPosition(sf::Vector2f(275, 15));
	score1.setString(std::to_string(0));
	score1.setCharacterSize(76);
	score1.setFillColor(sf::Color::Blue);

	score2.setFont(font);
	score2.setPosition(sf::Vector2f(875, 15));
	score2.setString(std::to_string(0));
	score2.setCharacterSize(76);
	score2.setFillColor(sf::Color::Red);
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
		if (ball.getPosition().x < 0)
		{
			player1.setScore((player1.getScore() + 1));
			score1.setString(std::to_string(player1.getScore()));
			ball.collisionResponse(3);
		}
	}
	else
	{
		if (Collision::checkBoundingBox(&ball, &player2))
		{
			ball.collisionResponse(2);
		}
		if (ball.getPosition().x > (window->getSize().x-25))
		{
			player2.setScore((player2.getScore() + 1));
			score2.setString(std::to_string(player2.getScore()));
			ball.collisionResponse(4);
		}
	}
	if (ball.getPosition().y > (window->getSize().y - 25))
	{
		ball.collisionResponse(5);
	}
	else if (ball.getPosition().y < 0)
	{
		ball.collisionResponse(6);
	}
	if (ball.getPosition().x > (window->getSize().x / 2) && (area1 == true))
	{
		area1 = false;
		ball.setFillColor(sf::Color::Red);
	}
	else if (ball.getPosition().x < (window->getSize().x / 2) && (area1 == false))
	{
		area1 = true;
		ball.setFillColor(sf::Color::Blue);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(player1);
	window->draw(player2);
	window->draw(line, 2, sf::LineStrip);
	window->draw(score1);
	window->draw(score2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(0,0,0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}