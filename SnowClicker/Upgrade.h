#pragma once
#include <iostream>
#include "ClickableObject.h"
#include "SnowBall.h"
#include "TextElement.h"
#include <SFML/Graphics.hpp>

class Upgrade : public ClickableObject
{
private:

	sf::String name;
	float boost = 0.1f;
	float cost;
	SnowBall *snowball;
	sf::Font font;
	sf::Text costText;
	sf::Text boostText;
	sf::Text totalBoostText;
	std::stringstream costStream;
	std::stringstream booststream;
	std::stringstream totalBoostStream;

public:

	Upgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color, SnowBall *sn);
	sf::Text createText(sf::Text textobject, int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text, float x, float y);
	sf::RectangleShape rect;
	float getCost();
	sf::String getName();
	float getBoost();
	sf::Text getCostText();
	sf::Text getBoostText();
	sf::Text getTotalBoostText();
	sf::Text updateTotalBoostText();
	virtual void action();

};

