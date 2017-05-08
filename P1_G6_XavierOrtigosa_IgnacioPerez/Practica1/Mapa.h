#pragma once
class Mapa
{
public:
	//atributos
	int dificultad;
	int numRows;
	int numColumns;
	char **md;
	//
	Mapa(int dificultat);
	void inicializarmapa();
	void printmapa();
	void cambiarpunto(int x, int y, char nuevoelemento);
	~Mapa();
};

