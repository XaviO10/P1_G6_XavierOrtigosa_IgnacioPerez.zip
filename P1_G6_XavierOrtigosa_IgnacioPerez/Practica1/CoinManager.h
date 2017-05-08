#pragma once
#include"Mapa.h"

class CoinManager
{

	Mapa &m;
public:
	//atributos
	int monedas;
	CoinManager(Mapa &m);
	void iniciarmonedasmapa();
	void eliminarmoneda();
	void cmonedas();
};

