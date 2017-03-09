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
	void copy(vector<string>& s);
	bool isAmpersand;
	~commandline();
private:

	char** myArgv;
	int myArgc;
	//;
	friend class sesnwdShell;
};
template<class Item>
commandline<Item>::commandline() {
	myArgc = 0;
	isAmpersand = false;
	myArgv = NULL;
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
	vector < string > tempvec;
	string word2;
	int i = 0;
	while (iss >> word2) {
		if (word2 == "&" && i == 0) {
			isAmpersand = true;
			cout << "is ampersand" << flush;
		}
		i += 1;
		tempvec.push_back(word2);
	}
	myArgc = i;
	copy (tempvec);

}
template<class Item>
void commandline<Item>::copy(vector<string>& s) {
	myArgv = (char**) malloc(sizeof(char*) * (s.size() + 1)); //s.size() + 1)
	for (int i = 0; i < myArgc; i++) {
		string temp = s[i];
		myArgv[i] = (char*) malloc(sizeof(temp) + 1);
		strcpy(myArgv[i], temp.c_str());
	}
	myArgv[myArgc] = NULL;

}
template<class Item>
commandline<Item>::~commandline() {
//	for (int i = 0; i < myArgc - 1; i++) {
//		free(myArgv[i]);
//	}
	//free(myArgv);
}

/* getCommand():
 * returns a pointer to the command portion
 * of the command-line (i.e., argv[0])
 */
template<class Item>
char* commandline<Item>::getCommand() const {
	char* ptr = myArgv[0];
	return ptr;
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

	return myArgv;
}

/*
 * getArgVector()
 * return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i])
 * @param i, an int that points to the ith command line word
 */
template<class Item>
char* commandline<Item>::getArgVector(int i) const {
	return myArgv[i];

}

/*
 * noAmpersand():
 * returns true if and only if no ampersand was given on the command-line
 */
template<class Item>
bool commandline<Item>::noAmpersand() const {
	return isAmpersand;
}

#endif /*COMMANDLINE_H_*/
