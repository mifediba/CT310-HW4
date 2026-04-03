#include "GameOfLife.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

	//Constructor with filename input
	GameOfLife::GameOfLife(std::string filename): generation(0){
        int w, h;
        std::string g;
        FileErrorCheck(filename); 
        FileContentCheck(filename);
        w = GetDimension(filename, 0);
        h = GetDimension(filename, 1);
        g = GetGrid(filename);

        this->width = w;
        this->height = h;
        this->grid = g;
        //std::cout << "Width: " << width << " Height: " << height << " Grid: " << grid  << " Generation: " << generation << std::endl;
    }
    //Constructor with dimensions and game board input
    GameOfLife::GameOfLife(int width, int height, std::string grid):width(width), height(height), grid(grid), generation(0){}
    //Copy constructor
	GameOfLife::GameOfLife(const GameOfLife& sourcegame){
        this->width = sourcegame.width;
        this->height = sourcegame.height;
        this->grid = sourcegame.grid;
        this->generation = sourcegame.generation;
    }   
    //Assignment operator
	GameOfLife& GameOfLife::operator=(const GameOfLife& sourcegame){
        this->width = sourcegame.width;
        this->height = sourcegame.height;
        this->grid = sourcegame.grid;
        this->generation = sourcegame.generation;
        return *this;
    }
	//Destrictor
    GameOfLife::~GameOfLife(){
    };


    void GameOfLife::NextGen(){
        int loopcounter = 0;
        int row, column;
        int nar, nac;
        int neighbor_row, neighbor_col;
        int num_live_neighbors = 0;
        int num_dead_neighbors = 0;
        std::string neighbors = "ABC";
        std::string new_grid ="";
        //std::cout << "Current grid: **" << grid << std::endl;
        for (char t : grid){//looping through each character in the grid
            row = loopcounter / width; //defining the width of the grid based on file width input
            column = loopcounter % width; //defining length of the grid based on file width input
            for (char nr : neighbors){ //neighbor row adjustment
                for (char nc : neighbors) {
                    if (nr == 'A' && nc == 'A'){//current cell
                        continue;
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
        //std::cout << "New grid: ***" << new_grid << std::endl;
        grid = new_grid; //replace current grid with newly calculated grid
        generation++; //increment up generation
    }
    void GameOfLife::NextNGen(int gens){
        //nextNGen function takes input:
        //integer g = generations
        //and prints the game board at generation g
        if (gens > 0){
            for (int j = 0; j < gens; j++){
                NextGen();
            }
        }
    }
    void GameOfLife::PrintGame() const{
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
    void GameOfLife::ToggleCell(int index){
        std::cout << "Toggle Cell index" << index << std::endl;
    }
    void GameOfLife::ToggleCell(int row, int col){
        std::cout << "Toggle Cell row/column" << row << " " << col << std::endl;
    }
    GameOfLife& GameOfLife::operator+=(int gens){
        if (gens > 0){
            NextNGen(gens);
        }
        else{
            throw std::invalid_argument("Negative generation not permitted.\n");
        }
        return *this;
    }
    GameOfLife GameOfLife::operator+(int gens) const{
        if (gens > 0){
            GameOfLife newGame = *this;
            newGame.NextNGen(gens);
            return newGame;
        }
        else{
            throw std::invalid_argument("Negative generation not permitted.\n");
        }

    }
    GameOfLife& GameOfLife::operator++(){
        NextGen();
        return *this;
    }
    void GameOfLife::FileErrorCheck(std::string filename){
        std::ifstream filein;
        filein.open(filename);
        if (!filein){
            //std::cerr << "File does not exist\n";
            throw std::invalid_argument("File does not exist.\n");
        }
        else{
            filein >> std::ws;
            std::string line;
            std::vector<int> dimensions;
            std::vector<char> values;
            if (filein.tellg() != 0)
            {
                throw std::invalid_argument("File is empty.\n");

            }
        }
    }
    void GameOfLife::FileContentCheck(std::string filename){
        int counter = 0;
        int row_counter = 0;
        std::ifstream filein;
        std::string line;
        std::vector<int> dimensions;
        std::vector<char> values;
        filein.open(filename);
        while (std::getline(filein, line)){
                std::stringstream linestring(line);
                if (counter == 0){
                    int d;
                    while (linestring >> d){
                        if (d == 0){
                            throw std::invalid_argument("Invalid input dimensions.\n");
                        }
                        dimensions.push_back(d);
                    }
                    if (dimensions.size() != 2){
                        throw std::invalid_argument("Incorrect number of input dimensions.\n");
                    }
                }
                else{
                    int column_counter = 0;
                    for (char v : line){
                        if (v != ' '){
                            if (v != 'X' && v != 'O'){
                                throw std::invalid_argument("Error: Invalid character, line " + std::to_string(counter + 1) + ".\n");
                            }
                            column_counter++;
                            if (v == 'X'){
                                values.push_back('0');
                            }
                            if (v == 'O'){
                                values.push_back('1');
                            }
                        }
                    }
                    row_counter++;
                    if (line.empty()){
                        row_counter--;
                        continue;
                    }
                    else if (column_counter != dimensions.back()) {
                        throw std::invalid_argument("Error: Incorrect number of columns, line " + std::to_string(counter + 1) + ".\n");
                    }
                    else if (counter > dimensions.front()) {
                        throw std::invalid_argument("Error: Incorrect number of rows, line " + std::to_string(counter + 1) + ".\n");
                    }
                }
                counter++;
            }
            if (row_counter != dimensions.front()){
                throw std::invalid_argument("Error: Incorrect number of rows, line " + std::to_string(counter + 1) + ".\n");
            }
    }
    std::string GameOfLife::GetGrid(std::string filename){
        std::string grid;
        std::ifstream filein;
        filein.open(filename);
        filein >> std::ws;
        std::string line;
        while(std::getline(filein, line)){
            for (char c : line){
                if (c == 'X'){
                    grid += "0";
                }
                else if (c == 'O'){
                    grid += "1";
                }
            }
        //	std::stringstream gridvalues(line);
        //	std::cout>> gridvalues >> std::endl;
        }
	    return grid;
    }
    int GameOfLife::GetDimension(std::string filename, int dimension){
	std::ifstream filein;
	filein.open(filename);
	filein >> std::ws;
	std::string dimensionline;
	std::getline(filein, dimensionline);
	std::stringstream integerstream(dimensionline); //select first dimension inputted in file 
	int height, width;
	integerstream >> height >> width;
	if (dimension == 0){
		return width;
	}
	else{
		return height;
	}
}
