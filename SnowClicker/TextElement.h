#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Player.h"
#include "SFML/Graphics.hpp"

class TextElement
{
private:
	sf::Text textElement;
	sf::Font *font;
	Player *player;

	sf::Vector2f textPosition(float x, float y);

public:
	TextElement();
	TextElement(Player *p, sf::Font *f);
	TextElement(int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text, float x, float y);
	void UpdateSnowCounter(sf::RenderWindow *window);
	sf::Text getText();
};

