#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ClickableObject.h"
#include "SnowBall.h"
#include "SnowCounter.h"

int main()
{
    Player player;
    SnowBall snowball(100, 200, 100, &player);
    SnowCounter snowCounter(&player);


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

            //check for input on the left mouse button 
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    snowball.checkForInput(window);
                }
            }
            
        }

        window.clear();
        window.draw(snowball.snowballShape);
        window.display();
    }

    return 0;
}