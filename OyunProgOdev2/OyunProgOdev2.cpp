#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

int _width = 400;
int _height = 750;
float x = 0;
int _speed = 1000;
float cerceveSuresi = 1.0f / 60.0f;



int main()
{
    
   
   
    player* player_sprite = new player();

    sf::RectangleShape rectShape({ 400, 50 });
    rectShape.setFillColor(sf::Color::Green);
    rectShape.setPosition(0, 700);

    sf::RenderWindow window(sf::VideoMode(_width, _height), "Space Impact");
    sf::Clock clock;
    sf::Clock clock_shoot;
    sf::Time gecenSure;
    sf::Time gecenSure_shoot;
    bool first_shoot = true;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        gecenSure += clock.restart();
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (gecenSure.asSeconds() >= cerceveSuresi) 
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player_sprite->rightMove();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player_sprite->leftMove();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if (first_shoot)
                {
                    player_sprite->shoot();
                    clock_shoot.restart();
                    first_shoot = false;
                }
                else
                {
                    gecenSure_shoot += clock_shoot.restart();
                    if (gecenSure_shoot.asSeconds() > 1)
                    {
                        player_sprite->shoot();
                        gecenSure_shoot -= gecenSure_shoot;
                    }
                }
                
                   
            }


            player_sprite->animController();
            player_sprite->bullets_move();
            window.clear(sf::Color::White);

            window.draw(player_sprite->player_sprite);
            window.draw(rectShape);

            
            for (int i = 0; i < player_sprite->bullet_count; i++)
            {
                window.draw(player_sprite->ui_bullets[i]);
            }
            for (int i = 0; i < player_sprite->bullets.size(); i++)
            {
                window.draw(player_sprite->bullets[i]);
            }
            window.display();
            gecenSure -= gecenSure;
        }
        
    }
    return 0;
}