#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ClickableObject.h"
#include "SnowBall.h"
#include "Upgrade.h"
#include "TextElement.h"
#include "Store.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Snow CLicker");

    Player player;

    //Credits for font: Khurasan.
    sf::Font font;
    font.loadFromFile("Fonts/CheeseToast.ttf");

    SnowBall snowball(100, 200, 150, &player);
    TextElement snowCounter(&player, &font);
    Store store(&player, &window, &snowCounter, &snowball);

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
                    snowball.checkForInput(window, &snowball.snowballShape);
                    snowCounter.UpdateSnowCounter(&window);
                    store.checkForInput(window);
                }
            }
            
        }
        
        //draw
        window.clear();
        window.draw(snowball.snowballShape);
        window.draw(snowCounter.getText());
        store.draw();
        window.display();
    }

    return 0;
}