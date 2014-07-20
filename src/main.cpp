#include "include/task.h"
#include "include/todo.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) {

	// converting all options to the string format
	string arg[argc];
	for (int i=0;i<argc;i++) arg[i]=argv[i];

	todo_t* todo = new todo();

	ifstream ifile ("~/.todo.txt");
	if (ifile.is_open()) {
		string line;
		while (getline (ifile, line)) {
			task_t* temp = new task_t (line);
			todo->push (temp);
		}
	}

	if (arg[1] == "list") {
		printf ("You selected the list option..\n");
	}
	else if (arg[1] == "add") {
		printf ("You selected the add option..\n");
	}
	else {
		// show usage Information.
		printf ("Invalid option selected..\n");
		exit (EXIT_FAILURE);
	}

	exit (EXIT_SUCCESS);
}
