#include "ClickableObject.h"
#include <iostream>


Vector2f position;

float shapeRadius;

//base constructor
ClickableObject::ClickableObject() 
{

}

//constructor
ClickableObject::ClickableObject(Vector2f pos, float radius)
{
	position = pos;
	shapeRadius = radius;
}

// check if the mouse position is within the bounds of the object
// return true if that is the case
bool ClickableObject :: inBounds(Vector2i mousepos)
{
	return (mousepos.x > position.x - shapeRadius && mousepos.x < position.x + shapeRadius) &&
		(mousepos.y > position.y - shapeRadius && mousepos.y < position.y + shapeRadius);

}

void ClickableObject::checkForInput()
{
	std::cout << "inBounds returned: " + inBounds(sf::Mouse::getPosition());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && inBounds(sf::Mouse::getPosition()) == true)
	{
		std::cout << "Mouse X position is: " + sf::Mouse::getPosition().x;
		std::cout << "Mouse Y position is: " + sf::Mouse::getPosition().y;
	}
}

void ClickableObject :: test() 
{
	std::cout << "hellow world.";
}




