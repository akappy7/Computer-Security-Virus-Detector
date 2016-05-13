#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Arguments.h"
#include "List_strings.h"

using namespace std;

int main(int argc, char *argv[]){
	bool match = 0;
	Arguments a;
	List_strings b;
	a.setParam(argc, argv);
	//a.getParam();
	b.setFile(a.returnStrFile());
	b.pA();
	string aString; 
	if( a.getInputCount() == 0){
		string aString; 
		char tempChar; 
		while (!cin.eof()) { 
   			cin.get(tempChar); 
   			aString += tempChar; 
		}
		int totalByte = 0;
		//******************************
   			b.resetBothIter();
			for( int i = 0; i < b.returnNumber(); i++){
				string name = b.getNextName();
				string signuture = b.getNextString();
				size_t found = aString.find(signuture);
				if (found!=std::string::npos){
					//cout<<found<<endl;
					//cout<<totalByte<<endl;
					if(!a.returnSilent()){
						cout<<"("<<totalByte+found<<"): "<< name<<endl;
					}
					match = 1;
				}
				if( a.returnStop()){
					break;
				}
				//totalByte = totalByte+ currentLine.size();
			}
			//*******************
	}
	//cout<<aString<<endl;

	for(int j = 0; j < a.getInputCount(); j++){
		bool file_flag = 0;
		FILE * pFile;
		/*if(!a.returnSilent()){
			cout<<"******"<<a.getInputFile(i)<<"*****"<<endl;
		}*/
		pFile=fopen(a.getInputFile(j).c_str(),"rb");
		if(pFile == NULL){
			perror("Error");
			continue;
		}//input file cannot open
		//char line[1024];
		char * line = new char[1024];
		int count = 0;
		int totalByte = 0;
		while( fgets(line,1024,pFile) ) {
			string currentLine;
			currentLine = line;
			count++;
			//cout<<"line "<<count<<": "<<currentLine;
			b.resetBothIter();
			for( int i = 0; i < b.returnNumber(); i++){
				string name = b.getNextName();
				string signuture = b.getNextString();
				size_t found = currentLine.find(signuture);
				if (found!=std::string::npos){
					//cout<<found<<endl;
					//cout<<totalByte<<endl;
					if(!a.returnSilent()){
						if(a.getInputCount() > 1){
							cout<<a.getInputFile(j);
						}
						cout<<"("<<totalByte+found<<"): "<< name<<endl;
					}
					match = 1;
					file_flag = 1;
					/*if( a.returnStop()){
						if(b.returnMal()){
							return 3;
						}//match and malform
						else{
							return 1;
						}//matches and no malformed string
						break;
					}*/
				}
			}
			if( a.returnStop() && file_flag){
				break;
			}
			totalByte = totalByte+ currentLine.size();
		}
	}
	/*b.resetBothIter();
	cout<<"Name:"<<b.getNextName()<<endl;
	cout<<"String:"<<b.getNextString()<<endl;*/
//	b.seeString();

	if( match && !b.returnMal()){
		return 1;
	}//matches and no malformed strs
	if( match && b.returnMal()){
		return 3;
	}//matches and malformed strs
	if( !match && b.returnMal() ){
		return 2;
	}//no matches and malformed string
	if(!match){
		return 0;
	}//no matches
}