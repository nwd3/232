/*
 * prompt.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: ses46
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/param.h>
#include <unistd.h>
using namespace std;
typedef char Item;
template<class Item>
class Prompt {
public:
	Prompt();
	string get() const;
	void set(const string &p);
private:
	string prompt;

};

template<class Item>
Prompt<Item>::Prompt() {
	char buffer[PATH_MAX];
	string currentDir;
	currentDir = getcwd(buffer, PATH_MAX); //from reference
	prompt = currentDir+"/$ ";

}

template<class Item>
string Prompt<Item>::get() const {
	return prompt;
}

template<class Item>
void Prompt<Item>::set(const string &p) {
	prompt = p+"$ ";
}
#endif
