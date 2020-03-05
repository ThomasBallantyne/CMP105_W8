#pragma once
#include "Framework/GameObject.h"
class Ball: public GameObject
{
public:
	Ball();
	~Ball();
	void update(float dt) override;
	void setVelocity(sf::Vector2f vel);
	void collisionResponse();
protected:
	sf::Vector2f velocity;
	sf::Vector2f changePos;
	float scale;
};

