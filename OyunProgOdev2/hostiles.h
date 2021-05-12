#pragma once
#include "hostile_spider_ship.h"
#include <vector>

class hostiles
{
public:
	int public_enemy_number_one_count; //LoL
	std::vector<hostile_spider_ship*> spider_ships;

	hostiles()
	{
		public_enemy_number_one_count = 1;
	}

	void spawn_spider_ship()
	{
		int randN = rand() % 10;
		if (spider_ships.size() < public_enemy_number_one_count &&
			randN > 5)
		{
			hostile_spider_ship* hss = new hostile_spider_ship();
			spider_ships.push_back(hss);
			
		}
	}
	void move_spider_ships(int player_x)
	{
		for (int i = 0; i < spider_ships.size(); i++)
		{
			spider_ships[i]->animController();
			spider_ships[i]->move(player_x);
		}
	}
	void move_spider_ship_bullets()
	{
		for (int i = 0; i < spider_ships.size(); i++)
		{
			spider_ships[i]->bullets_move();
		}
	}
};

