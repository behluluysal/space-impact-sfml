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

	hostile_spider_ship()
	{
		anim = 0;
		y_val = 0;
		x_val = rand() % 350;
		bullet_count = 2;
		spider_ship_textures[0].loadFromFile("resimler/uzay/yarasaucak/1.png", { 63, 57, 381, 391 });
		spider_ship_textures[1].loadFromFile("resimler/uzay/yarasaucak/2.png", { 63, 57, 381, 391 });
		spider_ship_textures[2].loadFromFile("resimler/uzay/yarasaucak/3.png", { 63, 57, 381, 391 });
		spider_ship_textures[3].loadFromFile("resimler/uzay/yarasaucak/4.png", { 63, 57, 381, 391 });
		spider_ship.setScale(0.1278f, 0.1278f);

		bullet.loadFromFile("resimler/uzay/bullet_red.png", { 46, 26, 36, 66 });
	}

	void animController(int player_x)
	{
		move(player_x);
		if (anim != 4)
			anim++;
		else
			anim = 0;
		spider_ship.setTexture(spider_ship_textures[anim]);
		//391 = 391 texture width height,
		// 391/100 =3,91 and 50/3,91 = 12,78
		spider_ship.setPosition(x_val, y_val);
		spider_ship.setRotation(180.0f);
	}
	void move(int player_x)
	{
		if (x_val < player_x)
		{
			x_val += 6;
			if (player_x - x_val < 50)
				shoot();
		}
		else
		{
			x_val -= 6;
			if (x_val - player_x < 50)
				shoot();
		}
			
	}
	void shoot()
	{
		if (bullet_count == 2)
		{
			sf::Sprite bul;
			bul.setScale(0.3f, 0.3f);
			bul.setTexture(bullet);
			bul.setPosition(x_val + 19.0f, y_val - 6);
			bul.setRotation(180.0f);
			bullets.push_back(bul);
			bullet_count--;
		}
		else if (bullet_count == 1)
		{
			if ((bullets[0].getPosition().y - spider_ship.getPosition().y) > 20)
			{
				sf::Sprite bul;
				bul.setScale(0.3f, 0.3f);
				bul.setTexture(bullet);
				bul.setPosition(x_val + 19.0f, y_val - 6);
				bul.setRotation(180.0f);
				bullets.push_back(bul);
				bullet_count--;
			}
			else
				return;
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
			}
		}
	}
};

