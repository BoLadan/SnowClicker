#include "ClickableObject.h"
#include <iostream>

//base constructor
ClickableObject::ClickableObject() 
{
	shapeRadius = 100;
}

//constructor
ClickableObject::ClickableObject(float x, float y, float radius)
{
	position.x = x;
	position.y = y;
	shapeRadius = radius;
}

// check if the mouse position is within the bounds of the object
// return true if that is the case
bool ClickableObject :: inBounds(Vector2i mousepos)
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
	std::cout << "Mouse X position is: " << mousepos.x << std::endl;
	std::cout << "Mouse Y position is: " << mousepos.y << std::endl;
	std::cout << "Magnitude is: " << magnitude << std::endl;
	std::cout << "state of bool is: " <<state <<std::endl;
	return state;
}

//
void ClickableObject::checkForInput(sf::RenderWindow &window)
{
	if (inBounds(sf::Mouse::getPosition(window)))
	{
		std::cout << "Action!!" << std::endl;
	}
	
}

void ClickableObject::setPosition(Vector2f pos)
{
	position = pos;
}

void ClickableObject :: test() 
{
	std::cout << "hellow world.";
}




