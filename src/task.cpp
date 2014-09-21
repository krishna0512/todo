#ifndef _TASK_CPP
#define _TASK_CPP

#include "include/task.h"

task_t::task_t (void) {
	this->m_state = 0;
	this->m_size = 0;
}

task_t::task_t (std::string s, bool state) {
	this->m_content = s;
	this->m_state = state;
	this->m_size = this->m_content.length();
}

task_t::task_t (std::string s) {
	this->m_state = (s[s.find_first_of("]") - 1] == 'x') ? true : false;
	this->m_content = s.substr (s.find_first_of("]") + 2);
	this->m_size = this->m_content.length();
}

std::string task_t::toString (void) {
	std::string t;
	t += (this->m_state == false) ? "[ ] " : "[x] ";
	t += this->m_content;
	return t;
}

std::string task_t::toStringFormatted (void) {
	std::string t = "";
	std::string green = "\x1b[1;32m", greenul = "\x1b[1;4;32m", red = "\x1b[1;31m", redul = "\x1b[1;4;31m", reset = "\x1b[0m";

	//if (this->m_state)
		//// green color
		//t += "\x1b[1;32m✓  " + this->m_content;
	//else
		//// red color.
		//t += "\x1b[1;31m✖  " + this->m_content;

	if (this->m_state) {
		t += green;
		bool flag = false;
		for (auto i:this->m_content) {
			if (i != '`')
				t += i;
			else {
				if (flag)
					t += reset + green;
				else
					t += greenul;
				flag ^= true;
			}
		}
	}
	else {
		t += red;
		bool flag = false;
		for (auto i:this->m_content) {
			if (i != '`')
				t += i;
			else {
				if (flag)
					t += reset + red;
				else
					t += redul;
				flag ^= true;
			}
		}
	}

	// reset color
	t += reset;
	return t;
}

bool task_t::equals (task_t* t) {
	if (not this->m_content.compare(t->m_content) and this->m_state == t->m_state) return true;
	else return false;
}

task_t::~task_t (void) {
}


#endif
