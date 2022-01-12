#include "SnowBall.h"
#include "ClickableObject.h"
 
SnowBall::SnowBall(float x, float y, float radius) : ClickableObject(x, y, radius)
{
	shapeRadius = radius;
	snowballShape.setRadius(radius);
	snowballShape.setFillColor(sf::Color::White);
	snowballShape.setPosition(x, y);
}



