#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


class Arguments{
	private:
	bool d;
	bool s;
	bool q;
	string strfile;
	string * inputFile;
	int inputCount;

	public:
		int a;

		Arguments();
		void setParam(int argc, char *argv[]);
		void getParam();
		string returnStrFile();
		int getInputCount();
		string getInputFile(int n);
		bool returnSilent();
		bool returnStop();
};

#endif