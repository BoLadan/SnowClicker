#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"

class SnowCounter
{
private:
	sf::Text counterText;
	sf::Font font;
	Player *player;

	sf::Vector2f textPosition();

public:
	SnowCounter(Player *p);
	void setText(std::string text);
	void configureTextSettings(sf::Font font, int characterSize, sf::Color color);
};

