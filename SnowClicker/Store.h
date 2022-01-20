#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Upgrade.h"
#include "TextElement.h"

class Store
{
private:
	
	Player *player;
	std::vector<std::shared_ptr<Upgrade>> upgrades;
	sf::RenderWindow *renderWindow;
	TextElement *snowCounter;
	SnowBall *snowball;

public:

	Store(Player *p, sf::RenderWindow* window, TextElement *sc, SnowBall *sn);
	std::shared_ptr<Upgrade> createUpgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color);
	Vector2f getNextButtonPosition();
	void addItem(std::shared_ptr<Upgrade> upgrade);
	void checkForInput(sf::RenderWindow &window);
	void checkForcurrency(size_t index);
	void purchase(size_t index);
	void draw();
};

