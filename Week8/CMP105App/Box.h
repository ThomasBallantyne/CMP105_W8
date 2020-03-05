#pragma once
#include "Framework/GameObject.h"
class Box: public GameObject
{
public:
	Box();
	~Box();
	void update(float dt) override;
	void setVelocity(sf::Vector2f vel);
	void collisionResponse();
protected:
	sf::Vector2f velocity;
	sf::Vector2f changePos;
	float scale;
};

