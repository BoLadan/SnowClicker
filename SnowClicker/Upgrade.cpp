#include "Upgrade.h"

Upgrade::Upgrade()
{
	boost = 0.1f;
}

Upgrade::Upgrade(float posX, float posY, float sizeX, float sizeY, int upgradeCost, sf::String upgradeName, float upgradeBoost) : ClickableObject(posX, posY, 0)
{
	//shapeRadius = radius;
	rect.setSize(sf::Vector2f(sizeX, sizeY));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(posX, posY));

	cost = upgradeCost;
	name = upgradeName;
	boost = upgradeBoost;
}

int Upgrade::getCost()
{
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
	std::cout << "Action initiated!" << std::endl;
}
