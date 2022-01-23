#include "SnowBall.h"
 
SnowBall::SnowBall(float x, float y, float radius, Player *p) : ClickableObject(x, y, radius)
{
	shapeRadius = radius;
	snowballShape.setRadius(radius);
	snowballShape.setFillColor(sf::Color::White);
	snowballShape.setPosition(x, y);
	player = p;

	if (!font.loadFromFile("Fonts/CheeseToast.ttf"))
	{
		std::cout << "COULD NOT LOAD FONT";
	}

	totalBoostText.setFont(font);
	totalBoostText.setCharacterSize(34);
	totalBoostText.setFillColor(sf::Color::White);
	totalBoostText.setStyle(sf::Text::Regular);
	totalBoostText.setString("Total Boost is: " + std::to_string(boost));
	totalBoostText.setPosition(450, 350);
}

float SnowBall::getScorePerClick()
{
	return initialScorePerClick * boost;
}

//Sets boost to an X amount to later aply it to the initial score per click.
void SnowBall::setBoost(float amount)
{
	boost += amount;
	
	totalBoostText.setString("Total Boost is: " + std::to_string(boost));
	std::cout << "boost is: " << boost << std::endl;
}

sf::Text SnowBall::getTotalBoostText()
{
	return totalBoostText;
}

//Adds score to player.
void SnowBall::action()
{
	player->addToScore(getScorePerClick());
}



