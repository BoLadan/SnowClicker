#pragma once
//specify all namespaces and library elements here
#include <SFML/Graphics.hpp>
#include <iostream>
using sf::Vector2f;
using sf::Vector2i;

class ClickableObject
{
	//virtual void action() = 0;

private:
	Vector2f position;

public:
	ClickableObject();
	ClickableObject(float x, float y, float radius);
	bool inBounds(Vector2i mousepos);
	void checkForInput(sf::RenderWindow &window);
	void setPosition(Vector2f pos);
	void test();

	float shapeRadius;
};

