#pragma once
#include "hostile_spider_ship.h"
#include "hostile_small_ship.h"
#include "space_mines.h"
#include "hostile_comm.h"

#include <vector>
#include <iostream>

class hostiles
{
public:
	int public_enemy_number_one_count; //LoL
	int public_enemy_number_two_count; //LoL
	int public_enemy_number_three_count; //LoL
	int public_enemy_number_four_count; //LoL

	std::vector<hostile_spider_ship*> spider_ships;
	std::vector<hostile_small_ship*> small_ships;
	std::vector<space_mines*> space_mine;
	std::vector<hostile_comm*> space_comms;

	hostiles()
	{
		public_enemy_number_one_count = 2;
		public_enemy_number_two_count = 2;
		public_enemy_number_three_count = 3;
		public_enemy_number_four_count = 3;
	}

	void spawn_hostile_ship()
	{
		int x = rand() % 10;
		bool flag = true;


		x = rand() % 12;
		if (x < 3)
		{
			if (spider_ships.size() < public_enemy_number_one_count)
			{
				hostile_spider_ship* hss = new hostile_spider_ship();
				spider_ships.push_back(hss);
			}
		}
		else if (x >= 3 && x<6)
		{
			if (small_ships.size() < public_enemy_number_two_count)
			{
				hostile_small_ship* hss = new hostile_small_ship();
				small_ships.push_back(hss);
			}
		}
		else if (x >= 6 && x< 8)
		{
			if (space_mine.size() < public_enemy_number_three_count)
			{
				space_mines* hss = new space_mines();
				space_mine.push_back(hss);
			}
		}
		else if (x >= 8 && x<12)
		{
			if (space_comms.size() < public_enemy_number_four_count)
			{
				hostile_comm* hss = new hostile_comm();
				space_comms.push_back(hss);
			}
		}
		std::cout << x << std::endl;
		
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

	void move_small_ships()
	{
		for (int i = 0; i < small_ships.size(); i++)
		{
			small_ships[i]->animController();
			small_ships[i]->move();
		}
	}
	void move_small_ship_bullets()
	{
		for (int i = 0; i < small_ships.size(); i++)
		{
			small_ships[i]->bullets_move();
		}
	}

	void move_space_mines()
	{
		for (int i = 0; i < space_mine.size(); i++)
		{
			space_mine[i]->animController();
			space_mine[i]->move();
		}
	}

	void move_hostile_comms()
	{
		for (int i = 0; i < space_comms.size(); i++)
		{
			space_comms[i]->animController();
			space_comms[i]->move();
		}
	}

};

