#include <SFML/Graphics.hpp>
#include "ClickableObject.h"
#include "SnowBall.h"

int main()
{
    SnowBall snowball;

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Snow CLicker");
    //sf::CircleShape shape(100.f);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snowball.snowballShape().setPosition(snowball.getPosition());
        window.draw(snowball.snowballShape());
        window.display();
    }

    return 0;
}