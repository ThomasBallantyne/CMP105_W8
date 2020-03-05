#include "Box.h"

Box::Box()
{
	velocity = sf::Vector2f(10, 0);
	scale = 20;
}

Box::~Box()
{

}

void Box::update(float dt)
{

	changePos = velocity * scale * dt;
	move(changePos);
}

void Box::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void Box::collisionResponse()
{
	velocity = -velocity;
}