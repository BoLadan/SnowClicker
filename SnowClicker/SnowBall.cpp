#include "SnowBall.h"
 
SnowBall::SnowBall(float x, float y, float radius, Player *p) : ClickableObject(x, y, radius)
{
	shapeRadius = radius;
	snowballShape.setRadius(radius);
	snowballShape.setFillColor(sf::Color::White);
	snowballShape.setPosition(x, y);
	player = p;
}

float SnowBall::getScorePerClick()
{
	return initialScorePerClick * boost;
}


void SnowBall::setBoost(float amount)
{
	boost += amount;
	std::cout << "boost is: " << boost << std::endl;
}

float SnowBall::getBoost()
{
	return boost;
}

void SnowBall::action()
{
	player->addToScore(getScorePerClick());
}



