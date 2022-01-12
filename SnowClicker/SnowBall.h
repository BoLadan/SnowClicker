#pragma once
#include "ClickableObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using sf::Vector2f;
using sf::Vector2i;

class SnowBall : public ClickableObject
{
public:
	SnowBall(float x, float y, float radius);
	sf::CircleShape snowballShape;


private:

};

