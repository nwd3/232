/* commandline.h
 * Created on: Feb 27, 2017
 * Project 3: A Command Shell
 * Author:Nathanael Dick, Steve Sykora
 * main.cpp: a driver to run a commandline shell that implements sesnwdShell,commandline,path,and prompt
 */
#include "sesnwdShell.h"
int main() {
	sesnwdShell myShell;
	cout << "Starting" << endl;
	myShell.run();
}

