#include <iostream>
#include "Mapa.h"
#include "Player.h"
#include "Input.h"
#include "CoinManager.h"

Player::Player(Mapa &m) : mapus(&m),
score(0),
exit (false)

{
	jugadorX = rand() % mapus->numRows;
	jugadorY = rand() % mapus->numColumns;
	mapus->md[jugadorY][jugadorX] = '@';
};

void Player::MovimientoPlayer(Input::Key key)
{
	char answer;
	mapus->md[jugadorY][jugadorX] = '.';
	switch (key)
	{
	case Input::Key::W:
		if (jugadorY == 0)
			break;
		else
		jugadorY -= 1; break;

	case Input::Key::A:
		if (jugadorX == 0)
			break;
		else
		jugadorX -= 1; break;

	case Input::Key::D:
		if (jugadorX == mapus->numColumns-1)
			break;
		else
		jugadorX += 1; break;

	case Input::Key::S:
		if (jugadorY == mapus->numRows-1)
			break;
		else
		jugadorY += 1; break;

	case Input::Key::ESC:
		system("cls");
		std::cout << "Want to exit? (Y/N)" << std::endl;
		std::cin >> answer;
		if (answer == 'Y' || answer == 'y') { Player::exit = true; }
		else break;
	};
	if (mapus->md[jugadorY][jugadorX] == '$') { totalscore += 1; score++; }
	mapus->md[jugadorY][jugadorX] = '@';
}

int Player::getscore() {
	
	return score;
}

Player::~Player()
{
}