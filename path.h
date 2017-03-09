/*
 * path.h
 *
 *  Created on: Feb 28, 2017
 *      Author: ses46
 */

//#ifndef PATH_H_
//#define PATH_H_
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

private:
	vector<string>* PATH;
	string pString;
};

template<class Item>
Path<Item>::Path() {
	pString = getenv("PATH");
	PATH=(vector<string>*)malloc(pString.size());
	split(pString, ':', *PATH);
}
/*
 *  return the index(of path vector) of the directory containing program
 * 	return -1 if program is in no directory
 * 	use opendir(), readdir(), and closedir()
 */

template<class Item>
int Path<Item>::find(const string& program) const { //TODO See if I need to do anything with mem
	DIR *dir;
	struct dirent *ent;
	string s;
	for (unsigned i = 0; i < PATH->size(); i++) {
		string temp = PATH->at(i);
		if ((dir = opendir(temp.c_str())) != NULL) {
			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {
				if (ent->d_name == program) {
					return i;
				}
			}
			closedir(dir);
		}
	}
	cout<<"Failed to find: "<<program<<endl;
	return -1;
}

template<class Item>
string Path<Item>::getDirectory(int i) const {
	return PATH->at(i);
}
//template<class Item>
//string Path<Item>::getpath() const {
//	return PATH;
//}

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


	/*	//print out of the vector for debugging
	 for(unsigned i = 0; i<out.size();i++){
	 cout<<i<<out[i]<<endl;
	 }*/
}

