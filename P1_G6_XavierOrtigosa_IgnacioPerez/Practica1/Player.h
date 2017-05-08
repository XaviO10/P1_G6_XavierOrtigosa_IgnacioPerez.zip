#pragma once
#include "Input.h"
#include "Mapa.h"
#include "CoinManager.h"
class Player
{	
public:
	bool exit;
	int score;
	Mapa *mapus;
	int getscore();
	int totalscore;
	int jugadorX;
	int jugadorY;
	Player(Mapa &m);
	void MovimientoPlayer(Input::Key key);
	~Player();
};

