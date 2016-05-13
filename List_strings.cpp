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
      cout << "String in str1: =" << *v << endl;
      v++;
   }
   vector<string>::iterator v1 = name.begin();
	while( v1 != name.end()) {
      cout << "String in name1: =" << *v1 << endl;
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


string convertString(char * tok){
	//char *temp = new char[strlen(tok)];
	string temp = "";
	int c = 0;
	int num = 0;
	for(int x = 0; x < (signed)strlen(tok); x++){
		if ( c == 0 && tok[x] == ' '){
			continue;
		}//skip blank space
		if(tok[x] == '\\' && tok[x+1] == 'x'){
			int t2;
			int t3;
			bool f1 = 0;
			bool f2 = 0;
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
			else if((int)tok[x+2] > 47 && (int)tok[x+2] < 58){
				t2 = ((int)tok[x+2] - 48);
			}
			else{
				f1 = 1;
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
			else if ( (int)tok[x+3] > 47 && (int)tok[x+3] <58){
				//cout<<"Tok[x+3]:"<<tok[x+3]<<endl;
				//cout<<"tok[x+3]:"<<(int)tok[x+3]<<endl;
				t3 = ((int)tok[x+3] - 48);
				//cout<<"T3:"<<t3<<endl;
			}
			else{
				f2 = 1;
			}
			if( f1 || f2){
				//temp[c] = tok[x];
				//temp[c+1] = tok[x+1];
				//temp[c+2] = tok[x+2];
				//temp[c+3] = tok[x+3];
				
				/*char c = tok[x];
				temp.append(&c);
				c = tok[x+1];
				temp.append(&c);
				c = tok[x+2];
				temp.append(&tok[x+2]);
				c = tok[x+3];
				temp.append(&c);*/

				temp.push_back(tok[x]);
				temp.push_back(tok[x+1]);
				temp.push_back(tok[x+2]);
				temp.push_back(tok[x+3]);

				/*cout<<tok[x]<<endl;
				cout<<tok[x+1]<<endl;
				cout<<tok[x+2]<<endl;
				cout<<tok[x+3]<<endl;*/
				//c = c + 4;
				x = x + 3;
				continue;
			}
			num = t2 *16 + t3;

			if(num == 0){
				temp.push_back('\0');
			}
			else{
				temp.push_back((char)num);
			}
			//c++;
			//cout<<temp<<endl;
			x = x + 3;
		}
		else{
			//temp[c] = tok[x];
			//char c = tok[x];
			temp.push_back(tok[x]);
			//c++;
		}
	//	cout<<"X:"<<x<<endl;
	}
	//tok = temp;
	//cout<<"TEMP: "<<temp<<endl;
	//cout<<"size:"<<temp.length()<<endl;
	return temp;
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
  			// cout<<"tok: "<< tok<<endl;
  			 if (tok == NULL){
  			 	cout<<"line " << lineC<<": Malformed line in " << strfile<<endl;
  			 	mal = 1;
  			 	continue;
  			 }
  			 string tok1 = convertString(tok);
  			 str.push_back(tok1);
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