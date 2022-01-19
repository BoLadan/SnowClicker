#pragma once
#include <iostream>
#include "ClickableObject.h"
#include <SFML/Graphics.hpp>

class Upgrade : public ClickableObject
{
private:

	sf::String name;
	float boost = 0.1f;
	int cost;

public:

	Upgrade(float posX, float posY, int upgradeCost, sf::String upgradeName, float upgradeBoost);
	sf::RectangleShape rect;
	int getCost();
	sf::String getName();
	float getBoost();
	virtual void action();

};

