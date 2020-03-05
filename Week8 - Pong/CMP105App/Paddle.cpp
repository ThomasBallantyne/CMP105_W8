#include "Paddle.h"

Paddle::Paddle()
{
	scale = 20;
}

Paddle::~Paddle()
{

}

void Paddle::update(float dt)
{
	if (controlType == 1)
	{
		changePos = velocity * scale * dt;
		move(changePos);
	}
}

void Paddle::handleInput(float dt)
{
	setVelocity(sf::Vector2f(0, 0));

	if (controlType == 1)
	{
		if (input->isKeyDown(sf::Keyboard::W))
		{
			velocity = sf::Vector2f(0, -30);
		}
		if (input->isKeyDown(sf::Keyboard::S))
		{
			velocity = sf::Vector2f(0, 30);
		}
	}
	else
	{
		setPosition(sf::Vector2f(1125, input->getMouseY()));
	}
}

void Paddle::setControlType(int type)
{
	controlType = type;
}

int Paddle::getScore()
{
	return score;
}

void Paddle::setScore(int sco)
{
	score = sco;
}