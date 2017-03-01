/*
 * sesnwd3shell.h
 *
 *  Created on: Feb 27, 2017
 *      Author: nwd3
 */

#ifndef SESNWDSHELL_H_
#define SESNWDSHELL_H_

#include <iostream>
#include "commandline.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class sesnwdShell {
public:
	sesnwdShell() {
	}
	sesnwdShell(commandline<char> cmd);
	sesnwdShell(const sesnwdShell& original);

	void run() {

		cout << "run";
	}
	commandline<char> myCommandline;
private:
};

#endif
