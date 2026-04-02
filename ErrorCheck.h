#ifndef ERRORCHECK_H
#define ERRORCHECK_H

#include <string>

class ErrorCheck{
	int argc;
	char** argv;

	public:
		ErrorCheck(int argc, char *argv[]);
		int inputArgs(int argc, char* argv[]);
		int getDimension(const char* filename, int dimension);
		std::string getGrid(const char* filename);
		int errorCheck(const char* filename);
};
#endif

