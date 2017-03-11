/*
 * path.h
 * Created on: Feb 27, 2017
 * Project 3: A Command Shell
 * Author: Steve Sykora
 * this class creates a Path class that creates a path to the directory
 * References:some online references
 */

//#ifndef PATH_H_
#define PATH_H_
#include<string.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
using namespace std;
template<class Item>
class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
	string getpath() const;
	void split(string& s, char delim, vector<string>& out);
	~Path();
private:
	//private variables
	vector<string>* PATH;
	string pString;
};
/*
 * Path(), a default constructor
 * default constructor mallocs space for the path
 * and constructs path variables
 */
template<class Item>
Path<Item>::Path() {
	pString = getenv("PATH");
	PATH = (vector<string>*) malloc(pString.size() + 10000);
	split(pString, ':', *PATH);
}
/**
 * destructor dletes path pointer
 */
template<class Item>
Path<Item>::~Path() {
	delete[] PATH;
}
/*
 *  return the index(of path vector) of the directory containing program
 * 	return -1 if program is in no directory
 * 	use opendir(), readdir(), and closedir()
 */

template<class Item>
int Path<Item>::find(const string& program) const { //TODO See if I need to do anything with mem
//define variables
	DIR *dir;
	struct dirent *ent;
	string s;
	//loops through
	for (unsigned i = 0; i < PATH->size(); i++) {
		string temp = PATH->at(i);
		//if directory is valid
		if ((dir = opendir(temp.c_str())) != NULL) {
			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {
				if (ent->d_name == program) {
					return i;
				}
			}
			//then close directory
			closedir(dir);
		}
	}
	return -1;

}

/*
 * getDirectory()
 * @param i, an int
 * returns a string at the index i
 */

template<class Item>
string Path<Item>::getDirectory(int i) const {
	return PATH->at(i);
}

/*
 * Takes a string, a char, and the vector you want to store the results in
 * Splits the string every time the delim is found
 */

template<class Item>
void Path<Item>::split(string& s, char delim, vector<string>& out) {
	int j = 0;
	for (unsigned i = 0; i < s.length(); i++) {
		if (s[i] == delim) {
			s[i] = '\n';
			out.push_back(s.substr(j, i - j));
			j = i + 1;
		}
	}
}

