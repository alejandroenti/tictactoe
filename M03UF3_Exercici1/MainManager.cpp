#include "MainManager.h"

void MainManager::Game() {

	while (isPlaying) {

		switch (currentScene) {
			case MENU:
				int optionSelected;
				bool optionValid;

				do {
					system("cls");
					optionValid = true;
					std::cout << " ---------- Tres en ratlla ----------\n" << std::endl;
					std::cout << " 1 - Nova partida" << std::endl;
					std::cout << " 2 - Carregar partida guardada" << std::endl;
					std::cout << " 3 - Sortir\n" << std::endl;

					std::cout << " Tria una opcio: ";
					std::cin >> optionSelected;

					switch (optionSelected)
					{
					case 1:
						currentScene = GAME;
						break;
					case 2:
						currentScene = LOAD;
						break;
					case 3:
						currentScene = EXIT;
						break;
					default:
						std::cout << "Enter a valid option!" << std::endl;
						optionValid = false;
					}
				} while (!optionValid);

				break;
			
			case GAME:
				b.PrintBoard();
				if (PlayerTurn()) {
					system("cls");
					continue;
				}
				if (currentScene != GAME) {
					b.ResetBoard();
					break;
				}
				if (CheckWin('X')) {
					winner = 'X';
					currentScene = GAMEOVER;
				}
				IATurn();
				if (CheckWin('O')) {
					winner = 'O';
					currentScene = MENU;
				}

				break;

			case GAMEOVER:

				b.PrintBoard();

				if (winner == 'X') {
					std::cout << "You won! Press any key to go to menu.\n" << std::endl;
				}
				else {
					std::cout << "You lost! Press any key to go to menu.\n" << std::endl;
				}

				b.ResetBoard();

				currentScene = MENU;

				break;

			case EXIT:

				std::cout << " Goodbye! Hope you enjoyed the game!" << std::endl;
				std::cout << "\n [+] Programmed by Alejandro Lopez" << std::endl;
				isPlaying = false;
		}

		system("pause");
		system("cls");
	}
}

bool MainManager::PlayerTurn() {

	std::string option = NextStep();

	if (option == "menu") {
		currentScene = MENU;
		return false;
	}

	if (option == "guardar") {
		std::string nameFile;
		bool validName = false;
		char option;

		while (!validName) {
			std::cout << "\n Amb quin nom vols guardar la partida? ";
			std::cin >> nameFile;

			if (nameFile == "menu") {
				std::cout << "\n [!] No es pot guardar la partida amb el nom 'menu'";
				continue;
			}

			std::ifstream file;
			file.open(nameFile + ".titacsave");
			if (file.is_open()) {
				std::cout << "\n [!] El fitxer ja existeix el vols sobreescriure? [s/n]: ";
				std::cin >> option;

				if (option != 's') {
					std::cout << "\n [*] El fitxer no sera sobreescrit." << std::endl;
					continue;
				}
			}

			file.close();

			std::ofstream outputFile;
			outputFile.open(nameFile + ".titacsave", std::ios::out | std::ios::trunc);

			for (int i = 0; i < MAP_SIZE; i++) {
				for (int j = 0; j < MAP_SIZE; j++) {
					outputFile << b.board[i][j];
				}
				outputFile << "\n";
			}

			outputFile.close();

			validName = true;
		}
		return true;
	}

	DemandInput();
	FillPlayerPosition();

	return false;
}

std::string MainManager::NextStep() {

	std::string option;

	std::cout << "\n Que vols fer? [jugar, guardar, menu]: ";
	std::cin >> option;

	return option;
}

void MainManager::DemandInput() {

	bool validInput = false;

	while (!validInput) {
		std::cout << "\n Introdueix la coordenada X: ";
		std::cin >> playerInput.x;

		if (!CheckInput(playerInput.x)) {
			std::cout << " [!] Invalid input [0, 2]" << std::endl;
			continue;
		}

		std::cout << "\n Introdueix la coordenada Y: ";
		std::cin >> playerInput.y;

		if (!CheckInput(playerInput.y)) {
			std::cout << "\n [!] Invalid input [0, 2]" << std::endl;
			continue;
		}

		if (b.board[playerInput.y][playerInput.x] != ' ') {
			std::cout << " [!] Coordenada ja en us!" << std::endl;
			continue;
		}

		validInput = true;
	}

	std::cout << "\n [*] Coordenada seleccionada: ( " << playerInput.x << ", " << playerInput.y << " )\n" << std::endl;
}

void MainManager::FillPlayerPosition() {

	b.board[playerInput.y][playerInput.x] = 'X';

}

void MainManager::IATurn() {

	IAInput();
	FillIAPosition();

}

void MainManager::IAInput() {

	bool validInput = false;

	while (!validInput) {

		iaInput.x = GenerateRandom(0, MAP_SIZE - 1);
		iaInput.y = GenerateRandom(0, MAP_SIZE - 1);

		if (b.board[iaInput.y][iaInput.x] == ' ') {
			validInput = true;
		}
	}
}

void MainManager::FillIAPosition() {

	b.board[iaInput.y][iaInput.x] = 'O';

}

bool MainManager::CheckWin(char icon) {
	
	bool hasWin = false;

	// HORIZONTAL
	for (int i = 0; i < MAP_SIZE; i++) {

		if (b.board[i][0] == icon && b.board[i][1] == icon && b.board[i][2] == icon)
			return true;

	}

	// VERTICAL
	for (int i = 0; i < MAP_SIZE; i++) {

		if (b.board[0][i] == icon && b.board[1][i] == icon && b.board[2][i] == icon)
			return true;

	}

	// DIAGONALS
	int i = 0;
	int j = 0;

	if (b.board[i][j] == icon && b.board[i++][j++] == icon && b.board[i++][j++] == icon)
		return true;

	i = 2;
	j = 0;

	if (b.board[i][j] == icon && b.board[i--][j++] == icon && b.board[i--][j++] == icon)
		return true;

	return hasWin;
}