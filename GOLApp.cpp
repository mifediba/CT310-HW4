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
      //Make game1
      GameOfLife game1("blinker.txt");
      game1.NextGen();
      game1+=9;
      game1.PrintGame();
      ++game1;
      game1.PrintGame();
      //game1.PrintGame();
      //game1.NextGen();
      //game1.PrintGame();
      //game1.NextGen();
      //game1.PrintGame();

      //Test copy constructor
      //GameOfLife game2 = game1;
      //game2.NextGen();
      //game2.PrintGame();
      //game1.PrintGame();

      //Test assignment operator
      //GameOfLife game2(5, 4, "00000000100010100010"); 
      //game2.NextGen();
      //game2.PrintGame();
      //game2 = game1;
      //std::cout << "Testing assignment operator: " << std::endl;
      //game2.PrintGame();
      //game2.NextGen();
      //game1.PrintGame();
      //game2.PrintGame();
      //
      //Make game2
      //GameOfLife game2(3,5,"000111000000000");
      //game2.NextGen();
      //game2.PrintGame();
      //game2.NextGen();
      //game2.PrintGame();
      //game2.NextGen();
      //game2.PrintGame();
      
   	 //so we don't get unused variable warning
      std::cout << argv[argc-1] << std::endl;
   }
   catch (std::invalid_argument& e){   
      std::cerr << e.what() <<std::endl;
   }
	return 0;
}

