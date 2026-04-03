#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include <string>

class GameOfLife{
private:
	int width;
	int height;
	std::string grid;
	int generation;
	std::string neighbors;	
	void FileErrorCheck(std::string filename);
	void FileContentCheck(std::string filename);
	void InputContentCheck(int width, int height, std::string grid);
	std::string GetGrid(std::string filename);
	int GetDimension(std::string filename, int dimension);

 public:
	GameOfLife(std::string filename);
	GameOfLife(int width, int height, std::string grid);
	GameOfLife(const GameOfLife&);
	GameOfLife& operator=(const GameOfLife&);
	~GameOfLife();

	void NextGen();
	void NextNGen(int gen);
	void PrintGame() const;
	void ToggleCell(int index);
	void ToggleCell(int row, int col);
	GameOfLife& operator+=(int gens);
	GameOfLife operator+(int gens) const;
	GameOfLife& operator++();


	//int parseInputs(int argc, char *argv[]);
};
#endif //GAMEOFLIFE_H
