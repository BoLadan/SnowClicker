#include "Upgrade.h"


Upgrade::Upgrade(sf::Vector2f pos, float upgradeCost, sf::String upgradeName, float upgradeBoost, sf::Color color, SnowBall* sn) : ClickableObject(pos.x, pos.y, 0)
{
	rect.setSize(sf::Vector2f(200, 75));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(pos));

	cost = upgradeCost;
	name = upgradeName;
	boost = upgradeBoost;
	snowball = sn;

	//text settings
	costStream << std::fixed << std::setprecision(2) << cost;
	costText = createText(costText, 20, sf::Color::Black, sf::Text::Regular, "Cost: " + costStream.str(), pos.x, pos.y);

	booststream << std::fixed << std::setprecision(0) << boost;
	boostText = createText(boostText, 20, sf::Color::Black, sf::Text::Regular, "Boost: " + booststream.str(), pos.x, pos.y + 20);

	totalBoostStream << std::fixed << std::setprecision(0) << snowball->getBoost();
	totalBoostText = createText(totalBoostText, 34, sf::Color::White, sf::Text::Regular, "Total boost: " + totalBoostStream.str(), 450, 350);
}

//creates and sets a taxt object and its settings.
sf::Text Upgrade::createText(sf::Text textobject, int characterSize, sf::Color color, sf::Uint32 textStyle, sf::String text, float x, float y)
{
	if (!font.loadFromFile("Fonts/CheeseToast.ttf"))
	{
		std::cout << "COULD NOT LOAD FONT";
	}

	textobject.setFont(font);
	textobject.setCharacterSize(characterSize);
	textobject.setFillColor(color);
	textobject.setStyle(textStyle);
	textobject.setString(text);
	textobject.setPosition(x, y);

	return textobject;
}

float Upgrade::getCost()
{
	return cost;
}

sf::String Upgrade::getName()
{
	return name;
}

float Upgrade::getBoost()
{
	return boost;
}

sf::Text Upgrade::getCostText()
{
	return costText;
}

sf::Text Upgrade::getBoostText()
{
	return boostText;
}

sf::Text Upgrade::getTotalBoostText()
{
	return totalBoostText;
}

sf::Text Upgrade::updateTotalBoostText()
{
	//totalBoostStream << std::fixed << std::setprecision(0) << "Total boost: " << snowball->getBoost();
	totalBoostText.setString(totalBoostStream.str());

	return totalBoostText;
}

void Upgrade::action()
{
	updateTotalBoostText();
}
