#include "ClickableObject.h"

//base constructor
ClickableObject::ClickableObject() 
{
	shapeRadius = 100;
}

ClickableObject::ClickableObject(float x, float y, float radius)
{
	position.x = x;
	position.y = y;
	shapeRadius = radius;
}

// check if the mouse position is within the bounds of the object
// return true if that is the case
bool ClickableObject :: inCircleBounds(Vector2i mousepos)
{
	bool state;
	Vector2f mouseposf = Vector2f(mousepos.x, mousepos.y);
	Vector2f positionToCenter = Vector2f(shapeRadius, shapeRadius);
	Vector2f center = position + positionToCenter;
	Vector2f distance = (center - mouseposf);

	float magnitude = sqrt(distance.x * distance.x + distance.y * distance.y);

	if (magnitude < shapeRadius)
	{
		state = true;
	}
	else
	{
		state = false;
	}

	return state;
}

bool ClickableObject::inRectBounds(Vector2i mousepos, sf::Shape *shape)
{
	return shape->getGlobalBounds().contains(sf::Vector2f(mousepos));
}

//Preform the action of the ClickableObject. Every Child class has it's own action method.
bool ClickableObject::checkForInput(sf::RenderWindow &window, sf::Shape *shape)
{
	if (dynamic_cast<const sf::CircleShape*>(shape) != nullptr && inCircleBounds(sf::Mouse::getPosition(window)) ||
		dynamic_cast<const sf::RectangleShape*>(shape) != nullptr && inRectBounds(sf::Mouse::getPosition(window), shape))
	{
		action();
		return true;
	}
	
}

void ClickableObject::setPosition(Vector2f pos)
{
	position = pos;
}

void ClickableObject::action()
{
}





