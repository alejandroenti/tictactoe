#include "Functionalities.h"

bool CheckInput(int num) {
	return num < MAP_SIZE && num >= 0;
}

int GenerateRandom(int min, int max) {
	return min + rand() % (max + 1 - min);
}

bool CheckIfFileExists(std::string file) {

	std::ifstream inputFile;

	inputFile.open(file);

	if (!inputFile.is_open()) {
		return false;
	}

	inputFile.close();
	
	return true;
}

