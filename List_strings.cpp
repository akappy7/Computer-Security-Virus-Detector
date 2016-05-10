#include "List_strings.h"
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <vector> 

List_strings::List_strings(){
	strfile = "";
	number_Strings = 0;
	mal = 0;
}
void List_strings::setFile(string file){
	strfile = file;
}

void List_strings::checkFile(FILE * file){
	if( file == NULL){
		perror("Error");
		exit (1);
	}

}

void List_strings::pA(){
	//cout<<"Update file: "<<strfile<<endl;
	parseStrings();
	//seeString();
}
void List_strings::seeString(){
	vector<string>::iterator v = str.begin();
	while( v != str.end()) {
      cout << "String in str1: = " << *v << endl;
      v++;
   }
   vector<string>::iterator v1 = name.begin();
	while( v1 != name.end()) {
      cout << "String in name2: = " << *v1 << endl;
      v1++;
   }
}

string List_strings::getNextName(){
	string temp;
	if(iter_name != name.end()){
		string temp = *iter_name;
		iter_name++;
		return temp;
	}
	else{
		return "";
	}
}
string List_strings::getNextString(){
	string temp;
	if(iter_str != str.end()){
		temp = *iter_str;
		iter_str++;
		return temp;
	}
	else{
		return "";
	}
}
void List_strings::resetBothIter(){
	iter_name = name.begin();
	iter_str = str.begin();
}


char * convertString(char * tok){
	char *temp = new char[strlen(tok)];
	int c = 0;
	int num = 0;
	for(int x = 0; x < (signed)strlen(tok); x++){
		if(tok[x] == '\\' && tok[x+1] == 'x'){
			int t2;
			int t3;
			if( tok[x+2] == 'a'  || tok[x+2] == 'A'){
				t2 = 10;
			}
			else if( tok[x+2] == 'b'  || tok[x+2] == 'B'){
				t2 = 11;
			}
			else if( tok[x+2] == 'c'  || tok[x+2] == 'C'){
				t2 = 12;
			}
			else if( tok[x+2] == 'd'  || tok[x+2] == 'd'){
				t2 = 13;
			}
			else if( tok[x+2] == 'e'  || tok[x+2] == 'E'){
				t2 = 14;
			}
			else if( tok[x+2] == 'f'  || tok[x+2] == 'F'){
				t2 = 15;
			}
			else{
				t2 = ((int)tok[x+2] - 48);

			}
			if( tok[x+3] == 'a'  || tok[x+3] == 'A'){
				t3 = 10;
			}
			else if( tok[x+3] == 'b'  || tok[x+3] == 'B'){
				t3 = 11;
			}
			else if( tok[x+3] == 'c'  || tok[x+3] == 'C'){
				t3 = 12;
			}
			else if( tok[x+3] == 'd'  || tok[x+3] == 'd'){
				t3 = 13;
			}
			else if( tok[x+3] == 'e'  || tok[x+3] == 'E'){
				t3 = 14;
			}
			else if( tok[x+3] == 'f'  || tok[x+3] == 'F'){
				t3 = 15;
			}
			else{
				t3 = ((int)tok[x+3] - 48);
			}
			num = t2 *16 + t3;
			//cout<<"num: "<<num<<endl;
			temp[c] = (char)num;
			c++;
			x = x + 2;
		}
		else{
			temp[c] = tok[x];
			c++;
		}
	}
	tok = temp;
	return tok;
}

void List_strings::parseStrings(){
	FILE * pFile;
	char line[1024];
	char * tok;
	int lineC = 0;
	//cout<<"Open File"<<endl;
	pFile=fopen(strfile.c_str(),"rb");
	if(pFile == NULL){
		perror("Error");
	}//str file cannot open
	else{
		 while( fgets(line,1024,pFile) ) {
		 	 lineC = lineC + 1;
       		 if(line[0] == '#')
       		 {
       		 	//cout<<"skipped #"<<endl;
       		 	continue;
       		 }
  			 tok = strtok (line,":");
  			// cout<<"line: "<< line<<endl; 
  			 tok = strtok (NULL, "\n");
  			 //cout<<"tok: "<< tok<<endl;
  			 if (tok == NULL){
  			 	cout<<"line " << lineC<<": Malformed line in " << strfile<<endl;
  			 	mal = 1;
  			 	continue;
  			 }
  			 tok = convertString(tok);
  			 str.push_back(tok);
  			 name.push_back(line);
  			 number_Strings++;
    	}
	}
}
int List_strings::returnNumber(){
	return number_Strings;
}

bool List_strings::returnMal(){
	return mal;
}