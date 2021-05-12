#pragma once
#include "player.h"
#include "hostiles.h"

class game_manager
{
public:
	player* playerC;
	hostiles* hostileH;

	game_manager()
	{
		 playerC = new player();
		 hostileH = new hostiles();
	}
};

