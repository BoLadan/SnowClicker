#pragma once
#include <iostream>
#include "ClickableObject.h"
#include "SnowBall.h"
#include <SFML/Graphics.hpp>

class Upgrade : public ClickableObject
{
private:

	sf::String name;
	float boost = 0.1f;
	float cost;
	SnowBall *snowball;

public:

	Upgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color, SnowBall *sn);
	sf::RectangleShape rect;
	float getCost();
	sf::String getName();
	float getBoost();
	virtual void action();

};

