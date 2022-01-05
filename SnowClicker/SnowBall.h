#pragma once
#include "ClickableObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using sf::Vector2f;
using sf::Vector2i;

class SnowBall : public ClickableObject
{
public:
	SnowBall();
	sf::CircleShape snowballShape();
	Vector2f getPosition();

private:
	Vector2f pos;

};

