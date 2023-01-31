#include <iostream>
#include <cstdlib>
#include <time.h>

#include "MainManager.h"

int main() {

	srand(time(NULL));

	MainManager manager;

	manager.Game();

	return 0;
}