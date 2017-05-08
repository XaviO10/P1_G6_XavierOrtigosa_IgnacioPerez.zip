#include "Mapa.h"
#include "CoinManager.h"
#include <iostream>

CoinManager::CoinManager(Mapa &m) : m(m)
{

	CoinManager::cmonedas();


	CoinManager::iniciarmonedasmapa();
};

void CoinManager::iniciarmonedasmapa() {
	int randrow;
	int randcolumn;
	for (int i = 0; i < monedas;) {
		randrow = rand() % m.numRows;
		randcolumn = rand() % m.numColumns;
		if (m.md[randrow][randcolumn] == '.') {
			m.cambiarpunto(randrow, randcolumn, '$');
			i++;
		}
	}

}

void CoinManager::cmonedas() {
	float max_monedas = ((static_cast<float>(m.numColumns * m.numRows) / 100) * 13);
	float min_monedas = ((static_cast<float>(m.numColumns * m.numRows) / 100) * 3);
	if (min_monedas < 1)min_monedas = 1;
	monedas = static_cast<int>((rand() % static_cast<int>(max_monedas - min_monedas) + static_cast<int> (min_monedas)));
}
void CoinManager::eliminarmoneda() {
	--monedas;
}


