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
	return scorePerClick;
}

void SnowBall::addScorePerClick(float amount)
{
	scorePerClick += (amount * getBoost());
}

float SnowBall::getBoost()
{
	return boost;
}

void SnowBall::setBoost(float amount)
{
	boost += amount;
}

void SnowBall::action()
{
	player->addToScore(scorePerClick);
	std::cout <<"score: " << player->getScore() << std::endl;
}



