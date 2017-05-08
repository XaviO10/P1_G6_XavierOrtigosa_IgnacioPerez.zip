#include "Mapa.h"
#include <iostream>



Mapa::Mapa(int dificultad):
dificultad(dificultad),
numRows(rand() % ((dificultad * 5 * 2) - (5 * dificultad)) + 5 * dificultad),
numColumns(rand() % ((dificultad * 5 * 2) - (5 * dificultad)) + 5 * dificultad)

{
	md = new char *[numRows];
	for (int i = 0; i < numRows; i++) {
		md[i] = new char[numColumns];
	}
}

void Mapa::inicializarmapa()
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			md[i][j] = '.';
		}
	}
}

void Mapa::printmapa()
{
	for (int i = 0; i < numRows; i++)
	{
		std::cout << std::endl;

		for (int j = 0; j < numColumns; j++)
		{
			std::cout << md[i][j];
		}
	}
}

void Mapa::cambiarpunto(int x, int y, char nuevoelemento) {
	md[x][y] = nuevoelemento;
}

Mapa::~Mapa()
{
}
