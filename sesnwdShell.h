/*
 * sesnwd3shell.h
 *
 * Created on: Feb 27, 2017
 * Author: nwd3
 */
//http://stackoverflow.com/questions/10068327/what-does-execve-do
#ifndef SESNWDSHELL_H_
#define SESNWDSHELL_H_
//very important
//http://stackoverflow.com/questions/2300581/how-do-you-fill-an-array-with-strings-in-c
#include <iostream>
#include <fstream>
#include <iostream>
#include "path.h"
#include "commandline.h"
#include "prompt.h"
using namespace std;

class sesnwdShell {
public:
	sesnwdShell() {
	}
	sesnwdShell(const sesnwdShell& original);
	void run() {
		while (1) { //this works well we just cntrl c out
			Prompt < string > prompt;
			cout << prompt.get();
			Path < string > p;
			commandline<char> cmd;
			cmd = commandline<char>(cin);
			cmd.getCommand();
			//no segmentation fault
			p.find(cmd.getCommand());
			//int path = p.find(cmd.getCommand());
			//cout << path << flush;
			//execve(p.getPath[path], cmd.getCommand(), p.pString);
		}
	}

private:

};

#endif
