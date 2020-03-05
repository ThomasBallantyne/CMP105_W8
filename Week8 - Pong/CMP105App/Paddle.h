#pragma once
#include "Framework/GameObject.h"
class Paddle: public GameObject
{
public:
	Paddle();
	~Paddle();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setControlType(int type);
	void setScore(int sco);
	int getScore();
protected:
	sf::Vector2f changePos;
	int controlType;
	float scale;
	int score;
};

