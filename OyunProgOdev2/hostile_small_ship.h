#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
class hostile_small_ship
{
public:
	sf::Texture small_ship_textures[5];
	sf::Sprite small_ship;
	int anim;
	int x_val;
	int y_val;
	sf::Texture bullet;
	int bullet_count;
	std::vector<sf::Sprite> bullets;
	bool isDestroyed;

	hostile_small_ship()
	{
		isDestroyed = false;
		anim = 0;
		y_val = 50;
		x_val = rand()% (350 - 50 + 1) + 50;
		bullet_count = 1;
		small_ship_textures[0].loadFromFile("resimler/uzay/smallship/1.png", { 71, 23, 483, 528 });
		small_ship_textures[1].loadFromFile("resimler/uzay/smallship/2.png", { 71, 23, 483, 528 });
		small_ship_textures[2].loadFromFile("resimler/uzay/smallship/3.png", { 71, 23, 483, 528 });
		small_ship_textures[3].loadFromFile("resimler/uzay/smallship/4.png", { 71, 23, 483, 528 });
		small_ship_textures[4].loadFromFile("resimler/uzay/smallship/4.png", { 71, 23, 483, 528 });

		small_ship.setScale(0.1278f, 0.1278f);
		small_ship.setRotation(180.0f);
		bullet.loadFromFile("resimler/uzay/bullet_red.png", { 46, 26, 36, 66 });

	}

	void animController()
	{
		if (anim != 4)
			anim++;
		else
			anim = 0;
		small_ship.setTexture(small_ship_textures[anim]);

		//391 = 391 texture width height,
		// 391/100 =3,91 and 50/3,91 = 12,78
		small_ship.setPosition(x_val, y_val);

	}
	void move()
	{
		y_val += 1;
		if ((y_val >= 0 && y_val <= 500 && bullet_count == 1))
		{
			shoot();
		}
	}
	void shoot()
	{
		if (bullet_count == 1)
		{
			sf::Sprite bul;
			bul.setScale(0.3f, 0.3f);
			bul.setTexture(bullet);
			bul.setPosition(x_val - 25.0f, y_val - 6);
			bul.setRotation(180.0f);
			bullets.push_back(bul);
			bullet_count--;
		}
		else
			return;
	}
	void bullets_move()
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].setPosition(bullets[i].getPosition().x, bullets[i].getPosition().y + 2);
			if (bullets[i].getPosition().y >= 700)
			{
				bullets.erase(bullets.begin() + i);
				bullet_count++;
			}
		}
	}
};

