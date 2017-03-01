/*
 * path.h
 *
 *  Created on: Feb 28, 2017
 *      Author: ses46
 */

#ifndef PATH_H_
#define PATH_H_

#include<string.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
template<class Item>
class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
private:

};

template<class Item>
Path<Item>::Path() {
	//do something with getenv()
	//talk to prof. Norman to get clearer instructions
}

template<class Item>
int Path<Item>::find(const string& program) const {
	//return the index(of path vector) of the directory containing program
	//return -1 if program is in no directory
	//use opendir(), readdir(), and closedir()
}

template<class Item>
string Path<Item>::getDirectory(int i) const {
	//return the name of the directory at index i
}
