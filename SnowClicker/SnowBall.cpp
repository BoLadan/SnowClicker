#include "SnowBall.h"

Vector2f pos;

SnowBall::SnowBall()
{
	
}

sf::CircleShape SnowBall::snowballShape()
{
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(getPosition().x, getPosition().y);
	return circle;
}

Vector2f SnowBall::getPosition()
{
	Vector2f pos;
	pos.x = 0;
	pos.y = 0;
	return pos;
}


