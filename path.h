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
	void split(string& s, char delim, vector<string>& out);

private:
	vector<string> PATH;
	string pString;
};

template<class Item>
Path<Item>::Path() {
	pString = getenv("PATH");
	split(pString, ':', PATH);

	cout << find("gnome-mines") << endl;
}

template<class Item>
int Path<Item>::find(const string& program) const {
	//return the index(of path vector) of the directory containing program
	//return -1 if program is in no directory
	//use opendir(), readdir(), and closedir()
	DIR *dir;
	struct dirent *ent;
	cout<<PATH[8].c_str()<<endl;
	if ((dir = opendir(PATH[7].c_str())) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			cout << ent->d_name << endl;
		}
		closedir(dir);
	}
	return -1;
}

template<class Item>
string Path<Item>::getDirectory(int i) const {
	//return the name of the directory at index i
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

	/*	//print out of the vector for debugging
	 for(unsigned i = 0; i<out.size();i++){
	 cout<<i<<out[i]<<endl;
	 }*/
}
