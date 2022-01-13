#pragma once
#include <iostream>

class Player
{
private:
	float score;

public:
	Player();
	void addToScore(float amount);
	float getScore();
};

