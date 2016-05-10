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

	for(int i = 0; i < a.getInputCount(); i++){
		FILE * pFile;
		if(!a.returnSilent()){
			cout<<"******"<<a.getInputFile(i)<<"*****"<<endl;
		}
		pFile=fopen(a.getInputFile(i).c_str(),"rb");
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
						cout<<"Found ["<< name<< "] at byte position "<<totalByte+found<<"."<<endl;
					}
					match = 1;
					if( a.returnStop()){
						if(b.returnMal()){
							return 3;
						}//match and malform
						else{
							return 1;
						}//matches and no malformed string
					}
				}
			}
			totalByte = totalByte+ currentLine.size();
		}
	}
	/*b.resetBothIter();
	cout<<"Name:"<<b.getNextName()<<endl;
	cout<<"String:"<<b.getNextString()<<endl;*/
	//b.seeString();

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