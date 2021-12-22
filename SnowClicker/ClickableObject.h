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

public:
	ClickableObject();
	ClickableObject(Vector2f pos, float radius);
	bool inBounds(Vector2i mousepos);
	void checkForInput();
	void test();
};

