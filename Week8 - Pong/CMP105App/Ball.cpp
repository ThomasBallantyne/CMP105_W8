#include "Ball.h"

Ball::Ball()
{
	velocity = sf::Vector2f(15,-15);
	scale = 20.f;
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	changePos = velocity * scale * dt;
	move(changePos);
}

void Ball::collisionResponse(int response)
{
	switch (response)
	{
	case 1:

		setPosition(76, getPosition().y);
		velocity.x = -velocity.x;
		break;

	case 2:

		std::cout << "hi";
		setPosition(1099, getPosition().y);
		velocity.x = -velocity.x;
		break;

	case 3:

		setPosition(625, 50);
		setVelocity(-15, -15);
		break;

	case 4:

		setPosition(550, 50);
		setVelocity(15, -15);
		break;

	case 5:

		setPosition(getPosition().x, 650);
		velocity.y = -velocity.y;
		break;

	case 6:

		setPosition(getPosition().x, 1);
		velocity.y = -velocity.y;
		break;

	}

}