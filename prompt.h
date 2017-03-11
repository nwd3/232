/*
 * prompt.cpp
 * Created on: Feb 27, 2017
 * Project 3: A Command Shell
 * Author: Steve Sykora, Nathanael Dick
 * this class creates a prompt class to get cwd
 * References: used online references to return current working directory
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
private:
	string prompt;

};

/*
 * Prompt()
 * default constructor constructs prompt:the current working directory
 */
template<class Item>
Prompt<Item>::Prompt() {
	char buffer[PATH_MAX];
	string currentDir;
	currentDir = getcwd(buffer, PATH_MAX); //found online from reference
	prompt = currentDir + "/$";

}

template<class Item>
string Prompt<Item>::get() const {
	return prompt;
}

#endif
