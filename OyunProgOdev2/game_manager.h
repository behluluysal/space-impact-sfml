#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "hostiles.h"
#include <iostream>
#include <vector>

class game_manager
{
public:
	player* playerC;
	hostiles* hostilesH;
	
	sf::Texture explosion_textures[17];

	struct explosion
	{
		int anim;
		sf::Sprite sprite;
	};

	std::vector<explosion> explosions;

	game_manager()
	{
		 playerC = new player();
		 hostilesH = new hostiles();

		 explosion_textures[0].loadFromFile("resimler/uzay/Effects/1_0.png", { 80, 90, 90, 90 });
		 explosion_textures[1].loadFromFile("resimler/uzay/Effects/1_1.png", { 70, 87, 101, 90 });
		 explosion_textures[2].loadFromFile("resimler/uzay/Effects/1_2.png", { 75, 88, 97, 88 });
		 explosion_textures[3].loadFromFile("resimler/uzay/Effects/1_3.png", { 68, 89, 106, 87 });
		 explosion_textures[4].loadFromFile("resimler/uzay/Effects/1_4.png", { 74, 89, 102, 89 });
		 explosion_textures[5].loadFromFile("resimler/uzay/Effects/1_5.png", { 69, 85, 114, 96 });
		 explosion_textures[6].loadFromFile("resimler/uzay/Effects/1_6.png", { 77, 76, 116, 103 });
		 explosion_textures[7].loadFromFile("resimler/uzay/Effects/1_7.png", { 69, 65, 133, 116 });
		 explosion_textures[8].loadFromFile("resimler/uzay/Effects/1_8.png", { 63, 58, 154, 131 });
		 explosion_textures[9].loadFromFile("resimler/uzay/Effects/1_9.png", { 48, 62, 175, 129 });
		 explosion_textures[10].loadFromFile("resimler/uzay/Effects/1_10.png", { 45, 47, 186, 151 });
		 explosion_textures[11].loadFromFile("resimler/uzay/Effects/1_11.png", { 44, 41, 197, 158 });
		 explosion_textures[12].loadFromFile("resimler/uzay/Effects/1_12.png", { 33, 34, 214, 171 });
		 explosion_textures[13].loadFromFile("resimler/uzay/Effects/1_13.png", { 76, 83, 98, 103 });
		 explosion_textures[14].loadFromFile("resimler/uzay/Effects/1_14.png", { 68, 77, 108, 115 });
		 explosion_textures[15].loadFromFile("resimler/uzay/Effects/1_15.png", { 73, 87, 103, 96 });
		 explosion_textures[16].loadFromFile("resimler/uzay/Effects/1_16.png", { 56, 82, 124, 113 });
	}

	void spawner()
	{
		hostilesH->spawn_spider_ship();
	}
	bool mover(bool game_status)
	{
		hostilesH->move_spider_ships(playerC->player_sprite.getPosition().x);
		hostilesH->move_spider_ship_bullets();
		
		//remove destroyed spiderships
		for (int j = 0; j < hostilesH->spider_ships.size(); j++)
		{
			if(hostilesH->spider_ships[j]->isDestroyed && hostilesH->spider_ships[j]->bullet_count == 2)
				hostilesH->spider_ships.erase(hostilesH->spider_ships.begin() + j);
		}
		//blue bullet hits spider ship
		for (int i = 0; i < playerC->bullets.size(); i++)
		{
			for (int j = 0; j < hostilesH->spider_ships.size(); j++)
			{
				if (hostilesH->spider_ships[j]->spider_ship.getGlobalBounds().intersects(playerC->bullets[i].getGlobalBounds()))
				{
					add_explosion(hostilesH->spider_ships[j]->spider_ship.getPosition(), hostilesH->spider_ships[j]->spider_ship.getRotation());
					hostilesH->spider_ships[j]->isDestroyed = true;
					playerC->bullets.erase(playerC->bullets.begin() + i);
					playerC->bullet_count++;
				}
			}
		}

		//spidership hits ground
		for (int i = 0; i < hostilesH->spider_ships.size(); i++)
		{
			if (hostilesH->spider_ships[i]->spider_ship.getPosition().y >= 700)
			{
				add_explosion(hostilesH->spider_ships[i]->spider_ship.getPosition(), hostilesH->spider_ships[i]->spider_ship.getRotation());
				hostilesH->spider_ships.erase(hostilesH->spider_ships.begin() + i);
				break;
			}
		}
		
		//spidership bullet hits player
		for (int i = 0; i < hostilesH->spider_ships.size(); i++)
		{
			for (int j = 0; j < hostilesH->spider_ships[i]->bullets.size(); j++)
			{
				if (hostilesH->spider_ships[i]->bullets[j].getGlobalBounds().intersects(playerC->player_sprite.getGlobalBounds()))
				{
					add_explosion(playerC->player_sprite.getPosition(), playerC->player_sprite.getRotation());
					hostilesH->spider_ships[i]->bullets.erase(hostilesH->spider_ships[i]->bullets.begin() + j);
					return false;
				}
			}
		}
		
		//spidership hits player
		if(game_status)
		for (int i = 0; i < hostilesH->spider_ships.size(); i++)
		{
			if (playerC->player_sprite.getGlobalBounds().intersects(hostilesH->spider_ships[i]->spider_ship.getGlobalBounds()))
			{
				add_explosion(hostilesH->spider_ships[i]->spider_ship.getPosition(), hostilesH->spider_ships[i]->spider_ship.getRotation());
				add_explosion(playerC->player_sprite.getPosition(), playerC->player_sprite.getRotation());
				hostilesH->spider_ships.erase(hostilesH->spider_ships.begin() + i);
				return false;
			}
		}





		return game_status;
	}

	void explosion_anims()
	{
		for (int i = 0; i < explosions.size(); i++)
		{
			if (explosions[i].anim == 17)
			{
				explosions.erase(explosions.begin() + i);
			}
			else
				explosions[i].sprite.setTexture(explosion_textures[explosions[i].anim++]);
		}
	}

	void add_explosion(sf::Vector2f t,float x)
	{
		explosion exp;
		exp.anim = 0;
		exp.sprite.setTexture(explosion_textures[exp.anim]);
		exp.sprite.setPosition(t);
		exp.sprite.setRotation(x);
		exp.sprite.setScale(0.5f,0.5f);
		explosions.push_back(exp);
	}
};

