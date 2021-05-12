#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>


class player
{
public:
	int anim;
	
	sf::Sprite player_sprite;
	sf::Sprite ui_bullets[8];
	sf::Texture bullet;
	int x_val;
	int y_val;

	sf::Sprite bul;
	std::vector<sf::Sprite> bullets;
	int bullet_count;
	
	int hp;
	sf::Texture playerTextures[8];
	
	player()
	{
		x_val = 175;
		y_val = 650;
		anim = 0;
		bullet_count = 3;
		hp = 3;
		playerTextures[0].loadFromFile("resimler/uzay/user/1.png", { 26, 26, 448, 448 });
		playerTextures[1].loadFromFile("resimler/uzay/user/2.png", { 26, 26, 448, 448 });
		playerTextures[2].loadFromFile("resimler/uzay/user/3.png", { 26, 26, 448, 448 });
		playerTextures[3].loadFromFile("resimler/uzay/user/4.png", { 26, 26, 448, 448 });
		playerTextures[4].loadFromFile("resimler/uzay/user/5.png", { 26, 26, 448, 448 });
		playerTextures[5].loadFromFile("resimler/uzay/user/6.png", { 26, 26, 448, 448 });
		playerTextures[6].loadFromFile("resimler/uzay/user/7.png", { 26, 26, 448, 448 });
		playerTextures[7].loadFromFile("resimler/uzay/user/8.png", { 26, 26, 448, 448 });
		player_sprite.setScale(0.1116f, 0.1116f);

		bullet.loadFromFile("resimler/uzay/bullet.png", { 46, 26, 36, 66 });

		int ui_bullet_pos = 260;
		for (int i = 0; i < 8; i++)
		{
			ui_bullets[i].setScale(0.4f,0.4f);
			ui_bullets[i].setTexture(bullet);
			ui_bullets[i].setPosition(ui_bullet_pos, 710);
			ui_bullet_pos += 15;
		}
	}
	void animController()
	{
		if (anim != 7)
			anim++;
		else
			anim = 0;
		player_sprite.setTexture(playerTextures[anim]);
		//448 texture width height,
		// 448/100 = 4,48 and 50/4,48 = 11,16
		player_sprite.setPosition(x_val, y_val);
	}
	void leftMove()
	{
		if (x_val > 1)
			x_val -= 6;
	}
	void rightMove()
	{
		if (x_val < 343)
			x_val += 6;
	}
	void shoot()
	{
		if (bullet_count > 0)
		{
			bul.setTexture(bullet);
			bul.setScale(0.3f, 0.3f);
			bul.setPosition(x_val + 19.0f, y_val + 6);
			bullets.push_back(bul);
			bullet_count--;
		}
	}
	void bullets_move()
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].setPosition(bullets[i].getPosition().x, bullets[i].getPosition().y - 3);
			if (bullets[i].getPosition().y <= 2)
			{
				bullets.erase(bullets.begin() + i);
				bullet_count++;
			}
		}
	}
};

