#include "SnowCounter.h"

//Credits for font: Hatf Type co.

SnowCounter::SnowCounter(Player *p)
{
	font.loadFromFile("Fonts/Chrismast Candy.ttf");
	configureTextSettings(font, 24, sf::Color::White);
	setText("Snow gained: " +  std::to_string(p->getScore()));
	std::cout << "Snow gained: " + std::to_string(p->getScore());
}

sf::Vector2f SnowCounter::textPosition()
{
	return sf::Vector2f();
}

void SnowCounter::setText(std::string text)
{
	counterText.setString(text);
}

void SnowCounter::configureTextSettings(sf::Font font, int characterSize, sf::Color color)
{
	counterText.setFont(font);
	counterText.setCharacterSize(characterSize);
	//counterText.setColor(color);
}
