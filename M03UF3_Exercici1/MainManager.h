#pragma once

#include <string>
#include <fstream>

#include "Functionalities.h"
#include "MapPosition.h"
#include "Board.h"

struct MainManager
{
	enum Scenes {MENU, LOAD, NEWGAME, LOADGAME, GAMEOVER};

	Scenes currentScene = MENU;
	bool isPlaying = true;

	Board b;
	MapPosition playerInput;
	MapPosition iaInput;
	char winner;

	void Game();
	bool PlayerTurn();
	std::string NextStep();
	void DemandInput();
	void FillPlayerPosition();
	void IATurn();
	void IAInput();
	void FillIAPosition();
	bool CheckWin(char icon);
};