#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	beachball.loadFromFile("gfx/Beach_Ball.png");
	goomba.loadFromFile("gfx/Goomba.png");
	
	ball1.setTexture(&beachball);
	ball1.setPosition(10, 100);
	ball1.setSize(sf::Vector2f(75, 75));

	ball2.setTexture(&beachball);
	ball2.setPosition(1115, 100);
	ball2.setSize(sf::Vector2f(75, 75));
	ball2.setVelocity(sf::Vector2f(-10, 0));

	box1.setTexture(&goomba);
	box1.setCollisionBox(0, 0, 75, 75);
	box1.setPosition(10, 300);
	box1.setSize(sf::Vector2f(75, 75));

	box2.setTexture(&goomba);
	box2.setCollisionBox(0, 0, 75, 75);
	box2.setPosition(1115, 300);
	box2.setSize(sf::Vector2f(75, 75));
	box2.setVelocity(sf::Vector2f(-10, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	box1.update(dt);
	box2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.collisionResponse();
		ball2.collisionResponse();
	}
	if (Collision::checkBoundingBox(&box1, &box2))
	{
		box1.collisionResponse();
		box2.collisionResponse();
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	window->draw(box1);
	window->draw(box2);
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