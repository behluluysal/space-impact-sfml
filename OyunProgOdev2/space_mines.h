#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class space_mines
{
public:
	sf::Texture space_mine_textures[2];
	sf::Sprite space_mine;
	int anim;
	int x_val;
	int y_val;

	space_mines()
	{
		x_val = rand() % (350 - 50 + 1) + 50;
		y_val = 0;
		anim = 0;
		space_mine_textures[0].loadFromFile("resimler/uzay/Spacemines/1.png", { 8, 8, 232, 232  });
		space_mine_textures[1].loadFromFile("resimler/uzay/Spacemines/2.png", { 8, 8, 232, 232 });
		//scale for 50px 21,55
		space_mine.setScale(0.2155f, 0.2155f);
	}

	void animController()
	{
		if (anim != 1)
			anim++;
		else
			anim = 0;
		space_mine.setTexture(space_mine_textures[anim]);

		//391 = 391 texture width height,
		// 391/100 =3,91 and 50/3,91 = 12,78
		space_mine.setPosition(x_val, y_val);
	}

	void move()
	{
		y_val += 1;
	}
};

