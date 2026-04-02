#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include <string>

class GameOfLife{
	int width;
	int height;
	std::string grid;
	int interval;
	int generation;
	std::string neighbors;
 public:
	GameOfLife(int width, int height, std::string grid);
	void NextGen();
	void NextNGen(int g, int i);
	void PrintGame();
	int parseInputs(int argc, char *argv[]);
	//int inputArgs(int argc, char *argv[]);
	//int errorCheck(const char* filename);

};
#endif //GAMEOFLIFE_H
