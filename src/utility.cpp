#include "include/utility.h"
#include <string>

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
	for (int i=0;i<n;i++) ret+=ret*10+(s[i]-'0');
	return (int)ret;
}
