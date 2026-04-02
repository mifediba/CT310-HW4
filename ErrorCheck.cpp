#include "ErrorCheck.h"
#include "GameOfLife.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

ErrorCheck::ErrorCheck(int argc, char *argv[]):argc(argc), argv(argv){}
int ErrorCheck::inputArgs(int argc, char *argv[]){
        if (argc < 2){
                //no filename
                std::cerr << "Error: No filename input\n";
                return 1;
        }
        else {
		int result = errorCheck(argv[1]);
                if (result != 0){
			return result;
		}
		//errorCheck(argv[1]);
		getDimension(argv[1], 0);
		getDimension(argv[1], 1);
		GameOfLife game1(getDimension(argv[1], 0), getDimension(argv[1], 1), getGrid(argv[1]));
      		if (argc ==  2){
			for (int i = 0; i < 10; i++){
				game1.PrintGame();
				game1.NextGen();
			}
			game1.PrintGame();
		}
		else if (argc == 3){
			game1.NextNGen(std::stoi(argv[2]), 1);
		}
		else if (argc == 4){
			game1.NextNGen(std::stoi(argv[2]), std::stoi(argv[3]));
		}
	}
	return 0;
}
int ErrorCheck::getDimension(const char* filename, int dimension){
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
std::string ErrorCheck::getGrid(const char* filename){
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
int ErrorCheck::errorCheck(const char* filename){
        int counter = 0;
        int row_counter = 0;
        std::ifstream filein;
        filein.open(filename);
        if (!filein){
                std::cerr << "File does not exist\n";
                return 1;
        }
	else{
                filein >> std::ws;
                std::string line;
                std::vector<int> dimensions;
                std::vector<char> values;
                if (filein.tellg() != 0){
                        std::cerr <<"File is empty\n";
                        return 2;
                }
                while(std::getline(filein,line)){
                        std::stringstream linestring(line);
                        if (counter == 0){
                                int d;
                                while (linestring >> d){
                                        if (d == 0){
                                                std::cout << "Invalid input dimensions\n";
                                                return 0;
                                        }
                                        dimensions.push_back(d);
                                }
                                if (dimensions.size() != 2){
                                        std::cerr << "Incorrect number of input dimensions\n";
                                        return 2;
                                }
                        }
                        else{
				int column_counter = 0;
                                for (char v : line){
                                        if (v != ' '){
                                                if (v != 'X' && v != 'O'){
                                                        std::cerr << "Error: Invalid character, line " << counter + 1 << std::endl;
                                                        return counter + 2;
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
                                else if (column_counter != dimensions.back()){
                                        std::cerr << "Error: Incorrect number of columns, line " << counter + 1 << std::endl;
                                        return counter + 2;
                                }
                                else if (counter > dimensions.front()){
                                        std::cerr << "Error: Incorrect number of rows, line " << counter + 1 << std::endl;
                                        return counter + 2;
                                }
                        }
                counter++;
                }
                if (row_counter != dimensions.front()){
                        std::cerr << "Error: Incorrect number of rows, line " <<counter + 1 << std::endl;
                        return counter + 2;
                }
        }
        return 0;
}
