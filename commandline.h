/* commandline.h
 * Student Name:Nathanael Dick/nwd3
 * Date:February 27, 2017
 * this class defines the commandline class which generates a commandline
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <cstring>

using namespace std;
const int SIZE = 12;
template<class Item>

class commandline {

	//public instance variables and methods declared
public:
	commandline();
	commandline(istream& in);
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
private:

	char * myArgv[];
//	vector<string> myArgv;
	int myArgc;
;
	friend class sesnwdShell;
};
template<class Item>
commandline<Item>::commandline() {
//	*myArgv = new char[SIZE];
	myArgc = 0;
}

/* commandline():
 * constructs the commandline by
 * reading a commandline from in, parsing it and building instance variables for argc and argv.
 * @param:in, a istream
 */
template<class Item>
commandline<Item>::commandline(istream& in) {

	string word;
	getline(in, word);
	istringstream iss(word);
	int i = 0;
	while (iss >> word) {
		myArgv[i] = strdup(word.c_str()); //from online ref
		i += 1;
	}
	myArgc = i;
/*	vector < Item > *myArgv = (vector<Item> *) malloc(sizeof(vector<Item> ));
	free((void *) myArgv);*/
}

/* getCommand():
 * returns a pointer to the command portion
 * of the command-line (i.e., argv[0])
 */
template<class Item>
char* commandline<Item>::getCommand() const {
	char *cmd=new char[100];
	cmd= myArgv[0];
/*//	cout<<myArgv[1]<<endl;
//	string cmd;
	*cmd = myArgv[0][0u];*/
	return cmd;
}

/*getArgCount():
 * return the number of command-line arguments on the command-line (i.e., argc)
 */
template<class Item>
int commandline<Item>::getArgCount() const {
	return myArgc;
}

/*
 * getArgVector():
 * return a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv
 */
template<class Item>
char** commandline<Item>::getArgVector() const {
	char ** argv;
	for (int i = 0; i < myArgc - 1; i++) {
		argv *= *myArgv[i];
	}
	return argv;
}

/*
 * getArgVector()
 * return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i])
 * @param i, an int that points to the ith command line word
 */
template<class Item>
char* commandline<Item>::getArgVector(int i) const {
	return *myArgv[i];

}

/*
 * noAmpersand():
 * returns true if and only if no ampersand was given on the command-line
 */
template<class Item>
bool commandline<Item>::noAmpersand() const {
	for (int i = 0; i < myArgc - 1; i++) {
		char * s = "&";
		if (!strcmp(myArgv[i], s)) {
			return true;
		} else {
			return false;
		}
	}
}

#endif /*COMMANDLINE_H_*/
