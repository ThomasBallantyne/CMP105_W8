#include "Ball.h"

Ball::Ball()
{
	velocity = sf::Vector2f(10, 0);
	scale = 20;
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	
	changePos = velocity * scale * dt;
	move(changePos);
}

void Ball::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void Ball::collisionResponse()
{
	velocity = -velocity;
}