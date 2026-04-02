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

   	 //so we don't get unused variable warning
    std::cout << argv[argc-1] << std::endl;
	return 0;
}

