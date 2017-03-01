/*
 * prompt.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: ses46
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <string.h>
using namespace std;

template<class Item>
class Prompt{
public:
	Prompt();
	string get() const;
private:

};

template<class Item>
Prompt<Item>::Prompt() {
	//use getcwd()
	//build the path to the working directory
}

template<class Item>
string Prompt<Item>::get() const {
}
