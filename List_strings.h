#ifndef LIST_STRINGS_H
#define LIST_STRINGS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector> 

using namespace std;


class List_strings{
	private:
		int number_Strings;
		string strfile;
		vector<string> name;
		vector<string> str;
		bool mal;
		vector<string>::iterator iter_str;
		vector<string>::iterator iter_name;
		void parseStrings(bool q);

	public:
	List_strings();
	void pA(bool q);
	void setFile(string file);
	void checkFile(FILE * file);
	void seeString();
	int returnNumber();
	string getNextName();
	string getNextString();
	void resetBothIter();
	bool returnMal();
};

#endif