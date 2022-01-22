#pragma once
#include <iostream>
#include <sstream>
#include "TextElement.h"
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
	void setBoost(float amount);
	sf::Text getTotalBoostText();

	virtual void action();

private:

	float initialScorePerClick = 0.1;
	float boost = 1;
	Player *player;
	sf::Text totalBoostText;
	sf::Font font;

};

