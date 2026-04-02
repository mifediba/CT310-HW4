#include "GameOfLife.h"
#include "ErrorCheck.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

GameOfLife::GameOfLife(int width, int height, std::string grid):width(width), height(height), grid(grid), interval(0), generation(0), neighbors("ABC"){}

void GameOfLife::next(){
	int loopcounter = 0;
	int row, column;
	int nar, nac;
	int neighbor_row, neighbor_col;
	int num_live_neighbors = 0;
	int num_dead_neighbors = 0;
	std::string new_grid ="";
	for (char t : grid){//looping through each character in the grid
		row = loopcounter / width; //defining the width of the grid based on file width input
		column = loopcounter % width; //defining length of the grid based on file width input
		for (char nr : neighbors){ //neighbor row adjustment
			for (char nc : neighbors) {
				if (nr == 'A' && nc == 'A'){//current cell
					//skip adjustment to current cell
				}
				else{ //loop through 8 possible neighbor cell coordinates based on their proximity to current cell 
					if (nr == 'A'){
						nar = 0; //nar = neighbor adjusted row
					}
					else if (nr == 'B'){
						nar = 1;
					}
					else if (nr == 'C'){
						nar = -1;
					}
					if (nc == 'A') {
						nac = 0; //nac = neighbor adjusted column
					}
					else if (nc == 'B'){
						nac = 1;
					}
					else if (nc == 'C'){
						nac = -1;
					}
					neighbor_row = row + nar; 
					neighbor_col = column + nac;
					if (neighbor_row > -1 && neighbor_row < height && neighbor_col > -1 && neighbor_col < width){ //only evaluate neighbors that can exist (non-zero, non-out-of-bounds)
						if (grid.at((neighbor_row * width) + neighbor_col) == '0'){
							num_dead_neighbors++; //count number of dead neighbors of current cell
						}
						else if (grid.at((neighbor_row * width) + neighbor_col) == '1'){
							num_live_neighbors++; //count number of live neighbors of current cell
						}
					}
				}
			}
		}
		if (t == '1' && (num_live_neighbors < 2 || num_live_neighbors > 3)){ //change current live cell value to dead if there are not exactly 2 living neighbors 
			new_grid += '0';
		}
		else if (t == '1' ){ //leave live cell value unchanged in cell has 2 living neighbors
			new_grid += '1';
		}
		else if (t == '0' && num_live_neighbors == 3){ //change dead cell value to live if have 3 living neighbors 
			new_grid += '1';
		}
		else {//keep dead cell dead if there are not 3 living cells around it
			new_grid += '0';
		}
		loopcounter++;
		num_dead_neighbors = 0; //reset dead cell count
		num_live_neighbors = 0; //reset live cell count
	}
	grid = new_grid; //replace current grid with newly calculated grid
	generation++; //increment up generation
}
void GameOfLife::nextNGen(int g, int i){
	//nextNGen function takes input:
	//integer g = generations
	//integer i = interval

	//and prints the game board at generation g
	if (g > 0){
		for (int j = 0; j < g; j++){
			if (j % i == 0){
				printGame();
			}
			next();
		}
	}
	printGame();
}
void GameOfLife::printGame() {
	int loopcounter = 0;
	std::cout << "Generation: " << generation << std::endl;
	for (char t : grid){
                loopcounter++;
                std::cout << t;
                if (loopcounter % width == 0){
                        std::cout <<"\n";
                }
        }
	//std::cout<<"Generation: " << grid << std::endl;
}

