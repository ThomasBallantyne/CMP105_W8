#pragma once
#include <iostream>
#include "Framework/GameObject.h"
class Ball: public GameObject
{
public:
	Ball();
	~Ball();
	void update(float dt) override;
	void collisionResponse(int response);
protected:
	sf::Vector2f changePos;
	float scale;
};

