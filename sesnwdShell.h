/*
 * sesnwd3shell.h
 * Created on: Feb 27, 2017
 * Project 3: A Command Shell
 * Author:Nathanael Dick, Steve Sykora
 * This program runs implements the commandline, path, and prompt classes
 * and creates a user shell that implements commands without using the existing command line
 * commands

 */
//some references others used
//http://stackoverflow.com/questions/2300581/how-do-you-fill-an-array-with-strings-in-c
//http://stackoverflow.com/questions/10068327/what-does-execve-do
//http://www.cs.ecu.edu/karl/4630/spr01/example1.html
#ifndef SESNWDSHELL_H_
#define SESNWDSHELL_H_

//included
#include <iostream>
#include "path.h"
#include "commandline.h"
#include "prompt.h"
#include <sys/wait.h>

using namespace std;

class sesnwdShell {
public:
	sesnwdShell() {
	}
	sesnwdShell(const sesnwdShell& original);
	void run() {
		//define our command line and path

		Path < string > p;
		commandline<char> cmd;
		//while loop runs so that command prompt continues to show
		while (1) {

			//declaring the prompt and outputting the prompt
			Prompt < string > prompt;
			cout << prompt.get();

			//explicitly initializing the commandline from the user input
			cmd = commandline<char>(cin);
			string com = cmd.getCommand();

			//exits on command "exit"
			if (com == "exit")
				break;
			//different process for working with cd
			if (com == "cd") {
				if (cmd.getArgCount() < 2) {
					//default cd goes to the home enviroment
					chdir(getenv("HOME"));
				} else {
					//change directory to the user input
					chdir(cmd.getArgVector(1));
				}
				//else we will run the command from the user
			} else {

				//try to make sure no error is outputted
				try {
					//some of this..creating process ids found online
					//create our id this is our child id
					pid_t pid;

					//the index will locate where that command is found
					int index = p.find(com);

					//the path sets the right executes
					string path = p.getDirectory(index) + '/' + com;

					//we fork here
					pid = fork();
					//if the child do this
					if (pid == 0) {
						//execute command
						execve(path.c_str(), cmd.getArgVector(), NULL);
					}
					//found this online a while loop to wait for parent process to finish
					if (cmd.ampersand) {
						while (wait(NULL) > 0) {
						}
					}
					//if error catch the exception and output error message
				} catch (const std::exception& e) {
					cout << com + ": command not found" << endl;
				}
			}
		}
	}

};

#endif  //end class
