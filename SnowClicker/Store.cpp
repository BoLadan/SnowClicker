#include "Store.h"


Store::Store(Player *p, sf::RenderWindow *window, TextElement *sc, SnowBall *sn)
{
	player = p;
	renderWindow = window;
	snowCounter = sc;
	snowball = sn;

	addItem(createUpgrade(getNextButtonPosition(), 2, "Snowman", 2, sf::Color::Red));
	addItem(createUpgrade(getNextButtonPosition(), 30, "Angle", 3, sf::Color::Green));
	addItem(createUpgrade(getNextButtonPosition(), 50, "Hot chocolate", 5, sf::Color::Blue));
	addItem(createUpgrade(getNextButtonPosition(), 80, "Sled", 6, sf::Color::Cyan));
	addItem(createUpgrade(getNextButtonPosition(), 100, "Ice skate", 8, sf::Color::Magenta));
	addItem(createUpgrade(getNextButtonPosition(), 150, "Candy cane", 10, sf::Color::Yellow));
}

//creates upgrades
std::shared_ptr<Upgrade> Store::createUpgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color)
{
	return std::make_unique<Upgrade>(pos, upgradeCost, upgradeName, upgradeBoost, color, snowball);
}

//Calculates the positions for the upgrades.
Vector2f Store::getNextButtonPosition()
{
	float firstPosition = 60;
	float distanceBetweenButtons = 125;
	float posX = 900;
	float posY = firstPosition + upgrades.size() * distanceBetweenButtons;
	return Vector2f(posX, posY);
}

//Adds item to the upgrades vector
void Store::addItem(std::shared_ptr<Upgrade> upgrade)
{
	upgrades.push_back(upgrade);
}

//Check for input on all the vector elements
void Store::checkForInput(sf::RenderWindow &window)
{
	for (size_t i = 0; i < upgrades.size(); i++)
	{
		if (upgrades[i]->checkForInput(window, &upgrades[i]->rect)) 
		{
			checkForcurrency(i);
		}
	}
}

//Get the clicked upgrade and the score of the player. 
//This function calculates if the player has enough to buy the desired upgrade.
void Store::checkForcurrency(size_t index)
{
	float score = player->getScore();
	float cost = upgrades[index]->getCost();

	if (score >= cost)
	{
		purchase(index);
		std::cout << "you have enough snow to purchase this upgrade." << std::endl;
	}
	else
	{
		std::cout << "You do not have enough snow to buy this upgrade..." << std::endl;
	}
}

//subrtact upgrade cost from the player's score, update the snow and boost counter and aply the boost to the snowball.
void Store::purchase(size_t index)
{
	float cost = upgrades[index]->getCost();
	
	player->subtractFromScore(cost);
	snowCounter->UpdateSnowCounter(renderWindow);
	snowball->setBoost(upgrades[index]->getBoost());
}

//draws some upgrade visuals
void Store::draw()
{
	for (size_t i = 0; i < upgrades.size(); i++)
	{
		renderWindow->draw(upgrades[i]->rect);
		renderWindow->draw(upgrades[i]->getCostText());
		renderWindow->draw(upgrades[i]->getBoostText());
		renderWindow->draw(upgrades[i]->getNameText());
	}
}
