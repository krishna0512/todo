#include "include/utility.h"
#include <string>
#include <fstream>

bool isNumber (std::string s) {
	int n=s.length();
	for (int i=0;i<n;i++) {
		if (s[i]>='0' && s[i]<='9') {}
		else return false;
	}
	return true;
}

int toNumber (std::string s) {
	int n=s.length();
	unsigned int ret=0;
	for (int i=0;i<n;i++) ret = ret*10+(s[i]-'0');
	return (int)ret;
}

std::string getContentFromEditor (std::string initial_content) {
	std::string filename = "/tmp/todo_temp.tmp";

	// If string is not empty only then output the string to the file (OBVIOUSLY!)
	if (initial_content != "") {
		std::ofstream ofile (filename);
		ofile<<initial_content;
		ofile.close();
	}

	std::string command = "vim " + filename;
	// getting the input from the vim command
	int status = system (command.c_str());

	if (status == -1)
		fprintf(stderr , "Internal Error. Please Check Command");

	std::ifstream ifile (filename);
	std::string final_content = "";
	getline (ifile, final_content);
	ifile.close();

	// deleting the temporary file after its use.
	remove (filename.c_str());

	return final_content;
}

void printHelp (void) {
	printf ("\nusage :\n\ttodo [all]\n\ttodo list [all]\n\ttodo add [<string>]\n\ttodo <number> [remove | delete]\n\ttodo <number> [done | undone]\n\ttodo <number> [change | modify | edit] [<string>]\n\ttodo cleanup\n\ttodo clear.\n");
}
