#pragma once
#include <iostream>
#include "ClickableObject.h"
#include <SFML/Graphics.hpp>

class Upgrade : public ClickableObject
{
private:

	sf::String name;
	float boost;
	int cost;

public:

	Upgrade();
	Upgrade(float posX, float posY, float sizeX, float sizeY, int upgradeCost, sf::String upgradeName, float upgradeBoost);
	sf::RectangleShape rect;
	int getCost();
	sf::String getName();
	float getBoost();
	virtual void action();

};

