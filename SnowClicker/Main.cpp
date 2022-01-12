#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ClickableObject.h"
#include "SnowBall.h"

int main()
{
    SnowBall snowball(100, 0, 100);


    sf::RenderWindow window(sf::VideoMode(1200, 800), "Snow CLicker");
    //sf::CircleShape shape(100.f);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //close the game with the escape button.
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            //if inBounds on ClickableObject is true, preform the action
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                snowball.checkForInput(window);
            }
            
        }

        window.clear();
        window.draw(snowball.snowballShape);
        window.display();
    }

    return 0;
}