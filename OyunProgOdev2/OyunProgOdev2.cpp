#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_manager.h"
#include <time.h>

int _width = 400;
int _height = 750;
float x = 0;
int _speed = 1000;
float cerceveSuresi = 1.0f / 60.0f;
bool game_status = true;


int main()
{
    srand(time(0));
    game_manager* game_managerG = new game_manager();

    sf::RectangleShape rectShape({ 400, 50 });
    rectShape.setFillColor(sf::Color::Green);
    rectShape.setPosition(0, 700);

    sf::RenderWindow window(sf::VideoMode(_width, _height), "Space Impact");
    sf::Clock clock;
    sf::Clock clock_shoot;
    sf::Clock clock_spawn;
    sf::Time gecenSure;
    sf::Time gecenSure_shoot;
    sf::Time gecenSure_spawn;
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
            if (game_status)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    game_managerG->playerC->rightMove();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    game_managerG->playerC->leftMove();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    if (first_shoot)
                    {
                        game_managerG->playerC->shoot();
                        clock_shoot.restart();
                        first_shoot = false;
                    }
                    else
                    {
                        gecenSure_shoot += clock_shoot.restart();
                        if (gecenSure_shoot.asSeconds() > 1)
                        {
                            game_managerG->playerC->shoot();
                            gecenSure_shoot -= gecenSure_shoot;
                        }
                    }
                }
            }
           

            gecenSure_spawn += clock_spawn.restart();
            if (gecenSure_spawn.asSeconds() > 1 && game_status)
            {
                game_managerG->spawner();
                gecenSure_spawn -= gecenSure_spawn;
            }
            
            game_status = game_managerG->mover(game_status);
            game_managerG->explosion_anims();
            game_managerG->playerC->animController();
            game_managerG->playerC->bullets_move();
            window.clear(sf::Color::White);

            if(game_status)
                window.draw(game_managerG->playerC->player_sprite);

            window.draw(rectShape);

            
            for (int i = 0; i < game_managerG->explosions.size(); i++)
            {
                window.draw(game_managerG->explosions[i].sprite);
            }
            for (int i = 0; i < game_managerG->playerC->bullet_count; i++)
            {
                window.draw(game_managerG->playerC->ui_bullets[i]);
            }
            for (int i = 0; i < game_managerG->playerC->bullets.size(); i++)
            {
                window.draw(game_managerG->playerC->bullets[i]);
            }
            for (int i = 0; i < game_managerG->hostilesH->spider_ships.size(); i++)
            {
                if(!game_managerG->hostilesH->spider_ships[i]->isDestroyed)
                    window.draw(game_managerG->hostilesH->spider_ships[i]->spider_ship);
            }   
            for (int i = 0; i < game_managerG->hostilesH->spider_ships.size(); i++)
            {
                for(int j = 0; j< game_managerG->hostilesH->spider_ships[i]->bullets.size();j++)
                    if(game_managerG->hostilesH->spider_ships[i]->bullets[j].getPosition().y > game_managerG->hostilesH->spider_ships[i]->spider_ship.getPosition().y+10)
                        window.draw(game_managerG->hostilesH->spider_ships[i]->bullets[j]);
            }
            window.display();
            gecenSure -= gecenSure;
        }
        
    }
    return 0;
}