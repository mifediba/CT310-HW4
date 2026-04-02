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
	GameOfLife(std::string filename);
	GameOfLife(int width, int height, std::string grid);
	GameOfLife(const GameOfLife&);
	GameOfLife& operator=(const GameOfLife&);
	~GameOfLife();

	void NextGen();
	void NextNGen(int g, int i);
	void PrintGame() const;
	void ToggleCell(int index);
	void ToggleCell(int row, int col);

	//int parseInputs(int argc, char *argv[]);
};
#endif //GAMEOFLIFE_H
