/*
 * sesnwd3shell.h
 *
 *  Created on: Feb 27, 2017
 *      Author: nwd3
 */

#ifndef SESNWDSHELL_H_
#define SESNWDSHELL_H_

#include <iostream>

using namespace std;

typedef double Item;
class sesnwdShell {
public:
	sesnwdShell();
	sesnwdShell(const sesnwdShell& original);
	~sesnwdShell();
	void run() {

		cout << "run";
	}

private:

};

#endif
