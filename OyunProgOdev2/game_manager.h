#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "hostiles.h"
#include <iostream>

class game_manager
{
public:
	player* playerC;
	hostiles* hostilesH;

	game_manager()
	{
		 playerC = new player();
		 hostilesH = new hostiles();
	}

	void spawner()
	{
		hostilesH->spawn_spider_ship();
	}
	void mover()
	{
		hostilesH->move_spider_ships(playerC->player_sprite.getPosition().x);
		hostilesH->move_spider_ship_bullets();
		for (int i = 0; i < playerC->bullets.size(); i++)
		{
			for (int j = 0; j < hostilesH->spider_ships.size(); j++)
			{
				if (playerC->bullets[i].getGlobalBounds().intersects(hostilesH->spider_ships[j]->spider_ship.getGlobalBounds()));
				std::cout << "test";
			}
		}
	}
};

