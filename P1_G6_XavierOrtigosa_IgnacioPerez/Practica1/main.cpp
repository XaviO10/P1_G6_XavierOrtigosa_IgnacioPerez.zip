#include <iostream>
#include "Mapa.h"
#include "CoinManager.h"
#include "Player.h"
#include <time.h>
#include <ctime>
#include <string>

int main() {

	srand(time_t(NULL));
	
	
	int difficulty;
	std::cout << "Introduce la dififucltad:" << std::endl << "1-Easy" << std::endl << "2-Medium" << std::endl << "3-Hard" << std::endl << "La dificultad elegida es: ";
	
	std::cin >> difficulty;

	
	//Inicializar mapa
	Mapa map(difficulty);

	map.inicializarmapa();

	//inicializar coin
	CoinManager coin(map);

	std::cout << "\n Objetive: you have to pick up: " <<coin.monedas << std::endl;
	std::cout << "\n";
	system("pause");
	system("cls");

	//iniciar player
	Player player(map);
	map.printmapa();
	Input::Key key;

	float tiempo;
	float time1 = clock();
	float time2;

	std::string r;
	do
	{
		key = Input::getKey();

		if (key != Input::Key::NONE) {
			player.MovimientoPlayer(key);
			system("cls");
			map.printmapa();
			std::cout << "\n Score: " << player.score << '/' << coin.monedas << std::endl;
			time2 = (clock() - time1) / 1000;
			std::cout << " Time: " << time2 << std::endl;
		}

		if (player.score == coin.monedas) {
			

			std::cout << std::endl << std::endl << "Your score has been: " << player.score << std::endl << "And your time: " << time2 << std::endl<< std::endl<<std::endl;
			
			std::cout << "************************" << std::endl << std::endl << std::endl;
			std::cout<< "  Play again?: Yes/No  " << std::endl << std::endl <<std::endl;
			std::cout << "************************" << std::endl;

			std::cin >> r;		
			
			if (r == "Yes" || r == "yes")
			{				
				coin.cmonedas();
				coin.iniciarmonedasmapa();
				player.score = 0;
				coin.monedas = static_cast<int>(coin.monedas + player.score);
				std::cout << "Press a key..." << std::endl;
				time1 = clock();
			}
			else if (r == "No" || r == "no")
			{
				player.exit = true;
				std::cout << "Press a key..." << std::endl;

			}
			else {
				system("cls");
				std::cout << "Try another command" << std::endl;
			}
		}

		if (key == Input::Key::ENTER)
			std::cout << "Llevas un score de: " << player.totalscore << std::endl;
		

	} while(player.exit == false);

	system("cls");
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "*******************************GAME OVER**************************************" << std::endl;
	std::cout << "******************************************************************************" << std::endl;


	system("pause");
		
	

}