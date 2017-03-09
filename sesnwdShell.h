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
#include <unistd.h>
#include "path.h"
#include "commandline.h"
#include "prompt.h"


#include <errno.h>
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
			vector<string> arg;
			string com = cmd.getCommand();
			//no segmentation fault
			if(com=="exit")
					break;
			int index=p.find(com);
			string path=p.getDirectory(index)+'/'+com;
//			char *chcom=new char[cmd.getArgCount()+1]();
//			for(int i = 0; i<cmd.getArgCount(); i++){
//				stpcpy(chcom, cmd.getArgVector(i));
//				cout<<chcom[i]<<endl;
//			}
//			chcom[cmd.getArgCount()]='\0';
			char **chcom = cmd.getArgVector();
//			cout<<"execv\n"<<path<<endl;
			execv(path.c_str(),chcom);
			cout<<strerror(errno)<<endl;
			//execve(p.getPath[path], cmd.getCommand(), p.pString);
		}
	}

private:

};

#endif
