#pragma once

#include <cstdlib>
#include <string>
#include <fstream>

#define MAP_SIZE 3

bool CheckInput(int num);
int GenerateRandom(int min, int max);
bool CheckIfFileExists(std::string file);