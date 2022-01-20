#include "Upgrade.h"


Upgrade::Upgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color, SnowBall* sn) : ClickableObject(pos.x, pos.y, 0)
{
	rect.setSize(sf::Vector2f(200, 75));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(pos));

	cost = upgradeCost;
	name = upgradeName;
	boost = upgradeBoost;
	snowball = sn;

	//std::cout << "cost on " << this << " is: " << cost << std::endl;
}

float Upgrade::getCost()
{
	//std::cout << "Returning cost on: " << this << std::endl;
	return cost;
}

sf::String Upgrade::getName()
{
	return name;
}

float Upgrade::getBoost()
{
	return boost;
}

void Upgrade::action()
{

}
