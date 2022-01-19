#include "TextElement.h"

//Constructor for the main snow counter text element.
TextElement::TextElement(Player *p, sf::Font *f)
{
	player = p;
	font = f;
	if (!f->loadFromFile("Fonts/CheeseToast.ttf"))
	{
		std::cout << "COULD NOT LOAD FONT";
	}

	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << player->getScore();

	textElement.setFont(*f);
	textElement.setCharacterSize(34);
	textElement.setFillColor(sf::Color::White);
	textElement.setStyle(sf::Text::Regular);
	textElement.setString("Snow gained: " + stream.str());
	textElement.setPosition(450,300);

	//std::cout << "Snow gained: " + std::to_string(player->getScore()) << std::endl;
}

// constructor for the regular text elements and other counters
TextElement::TextElement(sf::Font *f, int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text, float x, float y)
{
	if (!font->loadFromFile("Fonts/CheeseToast.ttf"))
	{
		std::cout << "COULD NOT LOAD FONT";
	}

	textElement.setFont(*f);
	textElement.setCharacterSize(characterSize);
	textElement.setFillColor(color);
	textElement.setStyle(textStyle);
	textElement.setString(text);
	textElement.setPosition(x, y);
}


void TextElement::UpdateSnowCounter(sf::RenderWindow *window)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << player->getScore();

	textElement.setString("Snow gained: " + stream.str());
	window->draw(getText());
}

sf::Vector2f TextElement::textPosition(float x, float y)
{
	sf::Vector2f pos;
	pos.x = x;
	pos.y = y;

	return pos;
}

sf::Text TextElement::getText()
{
	return textElement;
}
