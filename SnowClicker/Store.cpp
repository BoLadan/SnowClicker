#include "Store.h"


Store::Store(Player *p, sf::RenderWindow *window)
{
	player = *p;
	renderWindow = window;

	Upgrade snowman(800, 200, 15, "Snowman", 0.1f);
	addItem(snowman);
}

//Upgrade Store::createUpgrade(int upgradeCost, sf::String upgradeName, float upgradeBoost)
//{
//	Upgrade upgrade();
//	return  upgrade();
//}

void Store::addItem(Upgrade upgrade)
{
	upgrades.push_back(upgrade);
}

//Check for input on all the vector elements
void Store::checkForInput(sf::RenderWindow &window)
{
	for (size_t i = 0; i < upgrades.size(); i++)
	{
		if (upgrades[i].checkForInput(window, &upgrades[i].rect)) 
		{
			purchase(upgrades[i]);
		}
	}
}

//Get the clicked upgrade and the score of the player. 
//This function calculates if the player has enough to buy the desired upgrade.
void Store::checkForcurrency(Upgrade *upgrade)
{
	float score = player.getScore();
	float cost = upgrade->getCost();

	if (score >= cost)
	{
		purchase(*upgrade);
	}
}

void Store::purchase(Upgrade upgrade)
{
	float cost = upgrade.getCost();
	
	player.subtractFromScore(cost);
}

void Store::draw()
{
	for (size_t i = 0; i < upgrades.size(); i++)
	{
		renderWindow->draw(upgrades[i].rect);
	}
}
