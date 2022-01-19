#pragma once
#include <iostream>

class Player
{
private:
	float score;

public:
	Player();
	void addToScore(float amount);
	void subtractFromScore(float amount);
	float getScore();
};

