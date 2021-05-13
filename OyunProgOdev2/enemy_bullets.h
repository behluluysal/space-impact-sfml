#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
class enemy_bullets
{
public:
	std::vector<sf::Sprite> bullets;
	sf::Texture bullet;

	enemy_bullets()
	{
		bullet.loadFromFile("resimler/uzay/bullet_red.png", { 46, 26, 36, 66 });
	}

	void shoot(int x_val, int y_val)
	{
		sf::Sprite bul;
		bul.setScale(0.3f, 0.3f);
		bul.setTexture(bullet);
		bul.setPosition(x_val - 18.0f, y_val - 6);
		bul.setRotation(180.0f);
		bullets.push_back(bul);

		sf::Sprite bul2;
		bul2.setScale(0.3f, 0.3f);
		bul2.setTexture(bullet);
		bul2.setPosition(x_val - 18.0f, y_val - 70);
		bul2.setRotation(180.0f);
		bullets.push_back(bul2);
	}
};

