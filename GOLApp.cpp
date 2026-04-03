// GOLApp.cpp
//
// Placeholder file with main 
// replace with your own test code
// do not turn in

#include "GameOfLife.h"
#include "ErrorCheck.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main(int argc, char** argv){
   // ErrorCheck game1(argc, argv);
   // int result = game1.inputArgs(argc, argv);
//	return result;
   try{
      GameOfLife game1("Simple_Box_Up.txt");
      game1.PrintGame();
      GameOfLife game2(2, 2, "0000");
      game2.NextGen();
      game2.PrintGame();
      //game1.NextNGen(10, 2);
      //game1.PrintGame();
   	 //so we don't get unused variable warning
      std::cout << argv[argc-1] << std::endl;
   }
   catch (std::invalid_argument& e){   
      std::cerr << e.what() <<std::endl;
   }
	return 0;
}

