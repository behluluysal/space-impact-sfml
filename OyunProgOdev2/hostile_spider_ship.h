#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

class hostile_spider_ship
{
public:
	sf::Texture spider_ship_textures[4];
	sf::Sprite spider_ship;
	int anim;
	int x_val;
	int y_val;
	sf::Texture bullet;
	int bullet_count;
	std::vector<sf::Sprite> bullets;
	bool lock_on_target;

	hostile_spider_ship()
	{
		lock_on_target = true;
		anim = 0;
		y_val = 50;
		x_val = rand() % 350;
		bullet_count = 2;
		spider_ship_textures[0].loadFromFile("resimler/uzay/yarasaucak/1.png", { 63, 57, 381, 391 });
		spider_ship_textures[1].loadFromFile("resimler/uzay/yarasaucak/2.png", { 63, 57, 381, 391 });
		spider_ship_textures[2].loadFromFile("resimler/uzay/yarasaucak/3.png", { 63, 57, 381, 391 });
		spider_ship_textures[3].loadFromFile("resimler/uzay/yarasaucak/4.png", { 63, 57, 381, 391 });
		spider_ship.setScale(0.1278f, 0.1278f);
		spider_ship.setRotation(180.0f);
		bullet.loadFromFile("resimler/uzay/bullet_red.png", { 46, 26, 36, 66 });

	}

	void animController()
	{
		if (anim != 3)
			anim++;
		else
			anim = 0;
		spider_ship.setTexture(spider_ship_textures[anim]);
		
		//391 = 391 texture width height,
		// 391/100 =3,91 and 50/3,91 = 12,78
		spider_ship.setPosition(x_val, y_val);
		
	}
	void move(int player_x)
	{
		player_x += 50;
		
		y_val += 1;
		if (lock_on_target)
		{
			if (x_val <= player_x)
			{
				if (player_x - x_val >= 6)
				{
					if (y_val < 400)
						x_val += 2;
					if ((player_x - x_val <= 6) || (y_val>=400 && y_val<=500 &&bullet_count==2))
						shoot();
				}
			}
			else if (x_val > player_x)
			{
				if (x_val - player_x > 6)
				{
					if (y_val < 400)
						x_val -= 2;
					if ((x_val - player_x < 6) || (y_val >= 400 && y_val <= 500 && bullet_count == 2))
						shoot();
				}
			}
		}
	}
	void shoot()
	{
		if (bullet_count == 2)
		{
			sf::Sprite bul;
			bul.setScale(0.3f, 0.3f);
			bul.setTexture(bullet);
			bul.setPosition(x_val-18.0f , y_val - 6);
			bul.setRotation(180.0f);
			bullets.push_back(bul);
			bullet_count--;

			sf::Sprite bul2;
			bul2.setScale(0.3f, 0.3f);
			bul2.setTexture(bullet);
			bul2.setPosition(x_val -18.0f, y_val - 70);
			bul2.setRotation(180.0f);
			bullets.push_back(bul2);
			bullet_count--;
			lock_on_target = false;
		}
		else
			return;
	}
	void bullets_move()
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].setPosition(bullets[i].getPosition().x , bullets[i].getPosition().y + 3);
			if (bullets[i].getPosition().y >= 700)
			{
				bullets.erase(bullets.begin() + i);
				bullet_count++;
				if (bullet_count == 2)
					lock_on_target = true;
			}
		}
	}
};

