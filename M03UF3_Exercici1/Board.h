#pragma once

#include <iostream>

#include "Functionalities.h"

struct Board
{
	char board[MAP_SIZE][MAP_SIZE];

	void PrintBoard();
	void ResetBoard();
};