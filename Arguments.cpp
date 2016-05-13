#include "Arguments.h"
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

Arguments::Arguments(){
	d = 0;
	s = 0;
	q = 0;
	strfile="vdetect.str";
	inputCount = 0;
	inputFile = new string[10];
}

int Arguments::getInputCount(){
	return inputCount;
}
string Arguments::getInputFile(int n){
	if( n > inputCount){
		perror("Input count out of range");
		exit(1);
	}
	return inputFile[n];
}

void Arguments::setParam(int argc, char *argv[]){
	/*if(argc < 1 ){
		cout<<"Argument error"<<endl;
		exit(1);
	}*/
	for(int x = 1; x < argc; x++){
		if( !strcmp(argv[x], "-d")){
			d = 1;
			if ( x+1 == argc){
				perror("-d: requires signuture file");
				exit(1);
			}//nothing after -d
			x = x+1;
			strfile = argv[x];
		}
		else if( !strcmp(argv[x], "-q")){
			q = 1;
		}
		else if( !strcmp(argv[x], "-s")){
			s = 1;
		}
		else{
			inputFile[inputCount] = argv[x];
			inputCount++;
		}
	}
}
string Arguments::returnStrFile(){
	if(strfile == ""){
		cout<<"No string file"<<endl;
		exit(1);
	}
	return strfile;
}
void Arguments::getParam(){
	cout<<"Strfile: "<<strfile<<endl;
	cout<<"Bool d: "<<d<<endl;
	cout<<"Bool q: "<<q<<endl;
	cout<<"Bool s: "<<s<<endl;
	cout<<"Input file count: "<< inputCount<<endl;
	for(int i = 0; i < inputCount; i++){
		cout<<"File "<<i<<": "<<inputFile[i]<<endl;
	}
}

bool Arguments::returnSilent(){
	return q;
}
bool Arguments::returnStop(){
	return s;
}