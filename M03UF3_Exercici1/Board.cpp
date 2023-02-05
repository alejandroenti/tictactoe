#include "Board.h"

void Board::PrintBoard() {

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " +---+";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " | " << board[i][j] << " |";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " +---+";
		}
		std::cout << std::endl;
	}
}

void Board::ResetBoard() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			board[i][j] = ' ';
		}
	}
}