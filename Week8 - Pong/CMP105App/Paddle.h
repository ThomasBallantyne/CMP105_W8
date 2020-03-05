#pragma once
#include "Framework/GameObject.h"
class Paddle: public GameObject
{
public:
	Paddle();
	~Paddle();
	void update(float dt) override;
	void handleInput(float dt) override;

protected:

};

