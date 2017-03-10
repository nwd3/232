/*
 * sesnwd3shell.h
 *
 * Created on: Feb 27, 2017
 * Author: nwd3
 */
//http://stackoverflow.com/questions/10068327/what-does-execve-do
//http://www.cs.ecu.edu/karl/4630/spr01/example1.html
#ifndef SESNWDSHELL_H_
#define SESNWDSHELL_H_
//very important
//http://stackoverflow.com/questions/2300581/how-do-you-fill-an-array-with-strings-in-c
#include <iostream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "path.h"
#include "commandline.h"
#include "prompt.h"
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
using namespace std;

class sesnwdShell {
public:
	sesnwdShell() {
	}
	sesnwdShell(const sesnwdShell& original);
	void run() {
		commandline<char> cmd;
		Path < string > p;
		while (1) {
			Prompt < string > prompt;
			cout << prompt.get();

			cmd = commandline<char>(cin);
			vector < string > arg;
			string com = cmd.getCommand();
//			cmd.print();
			if (com == "exit")
				break;
			if (com == "cd") {
				if(cmd.getArgCount()<2){
					chdir(getenv("HOME"));
				}else{
					chdir(cmd.getArgVector(1));
				}
//				cout << strerror(errno) << endl;
			} else if (cmd.ampersand == true) {
				pid_t child_pid;
				int index = p.find(com);
				string path = p.getDirectory(index) + '/' + com;

				child_pid = fork();
				int child_status;
				if (child_pid == 0) {
					execve(path.c_str(), cmd.getArgVector(), NULL);
				}
				while (wait(NULL) > 0) {
				}
			} else {

			}
			//cout << strerror(errno) << endl;
			//execve(p.getPath[path], cmd.getCommand(), p.pString);
		}
		//run();
	}

private:

}
;

#endif
