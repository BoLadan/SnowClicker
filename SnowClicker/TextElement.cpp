#include "TextElement.h"

//Constructor for the counter text elements
TextElement::TextElement(Player *p, sf::Font *f)
{
	player = p;
	font = f;
	if (!f->loadFromFile("Fonts/CheeseToast.ttf"))
	{
		std::cout << "COULD NOT LOAD FONT";
	}

	textElement.setFont(*f);
	textElement.setCharacterSize(24);
	textElement.setFillColor(sf::Color::White);
	textElement.setStyle(sf::Text::Regular);
	textElement.setString("Snow gained: " + std::to_string(player->getScore()));

	std::cout << "Snow gained: " + std::to_string(player->getScore()) << std::endl;
}

// constructor for the regular text elements
TextElement::TextElement(sf::Font *f, int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text)
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
}


void TextElement::UpdateSnowCounter(sf::RenderWindow *window)
{
	textElement.setString("Snow gained: " + std::to_string(player->getScore()));
	window->draw(getText());
}

sf::Vector2f TextElement::textPosition()
{
	return sf::Vector2f();
}

sf::Text TextElement::getText()
{
	return textElement;
}
