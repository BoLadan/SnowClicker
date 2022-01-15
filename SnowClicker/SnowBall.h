#pragma once
#include <iostream>
#include "ClickableObject.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
using sf::Vector2f;
using sf::Vector2i;

class SnowBall : public ClickableObject
{
public:

	SnowBall(float x, float y, float radius, Player *p);
	sf::CircleShape snowballShape;
	float getScorePerClick();
	void addScorePerClick(float amount);
	float getBoost();
	void setBoost(float amount);
	virtual void action();

private:

	float scorePerClick = 0.1;
	float boost = 1;
	Player *player;

};

