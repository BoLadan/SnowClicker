#include "ClickableObject.h"


Vector2f position;

float shapeRadius;

ClickableObject::ClickableObject() 
{

}

ClickableObject::ClickableObject(Vector2f pos, float radius)
{
	position = pos;
	shapeRadius = radius;
}

// check if the mouse position is within the bounds of the object
// return true if that is the case``
bool ClickableObject :: inBounds(Vector2f mousepos)
{
	return (mousepos.x > position.x - shapeRadius && mousepos.x < position.x + shapeRadius) &&
		(mousepos.y > position.y - shapeRadius && mousepos.y < position.y + shapeRadius);

}

void ClickableObject :: test() 
{
	std::cout << "hellow world.";
}




