#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class hostile_comm
{
public:
	sf::Texture space_comm_textures[3];
	sf::Sprite space_comm;
	int anim;
	int x_val;
	int y_val;

	hostile_comm()
	{
		x_val = rand() % (350 - 50 + 1) + 50;
		y_val = 0;
		anim = 0;
		space_comm_textures[0].loadFromFile("resimler/uzay/comm/1.png", { 220, 220, 590, 580 });
		space_comm_textures[1].loadFromFile("resimler/uzay/comm/2.png", { 220, 220, 590, 580 });
		space_comm_textures[2].loadFromFile("resimler/uzay/comm/3.png", { 220, 220, 590, 580 });
		//scale for 50px 8,474
		space_comm.setScale(0.08474f, 0.08474f);
	}

	void animController()
	{
		if (anim != 2)
			anim++;
		else
			anim = 0;
		space_comm.setTexture(space_comm_textures[anim]);

		//391 = 391 texture width height,
		// 391/100 =3,91 and 50/3,91 = 12,78
		space_comm.setPosition(x_val, y_val);
	}

	void move()
	{
		y_val += 1;
	}
};

