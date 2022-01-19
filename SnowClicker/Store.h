#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Upgrade.h"

class Store
{
private:
	
	Player player;
	std::vector<Upgrade> upgrades;
	sf::RenderWindow *renderWindow;

public:

	Store(Player *p, sf::RenderWindow* window);
	//Upgrade createUpgrade(int upgradeCost, sf::String upgradeName, float upgradeBoost);
	void addItem(Upgrade upgrade);
	void checkForInput(sf::RenderWindow &window);
	void checkForcurrency(Upgrade *upgrade);
	void purchase(Upgrade upgrade);
	void draw();
};

