#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"

class TextElement
{
private:
	sf::Text textElement;
	sf::Font *font;
	Player *player;

	sf::Vector2f textPosition();

public:
	TextElement(Player *p, sf::Font *f);
	TextElement(sf::Font *f, int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text);
	void UpdateSnowCounter(sf::RenderWindow *window);
	sf::Text getText();
};

