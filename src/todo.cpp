#ifndef _TODO_CPP
#define _TODO_CPP

#include "include/todo.h"

todo_t::todo_t (void) {
	this->m_length = 0;
}

todo_t::~todo_t (void) {

}

size_t todo_t::size (void) {
	return this->m_length;
}

void todo_t::push (task_t* task) {
	this->m_list.push_back (task);
	this->m_length++;
}

task_t* todo_t::getTask (unsigned int index) {
	if (index < 0 || index >= this->m_length) {
		// TODO: raise the Exception and catch it at the main
	}

	for (int i=0;i<this->m_length;i++) {
		if (i+1 == index) return this->m_list[i];
	}
	return NULL;
}

void todo_t::setDone (unsigned int index) {
	if (index < 0 || index >= this->m_length) {
		//TODO: raise the Exception and catch it at the main
	}

	this->m_list[--index]->m_state = true;
}

void todo_t::modifyTask (unsigned int index, std::string s) {
	if (index < 0 || index >= this->m_length) {
		//TODO: raise the Exception and catch it at the main
	}

	this->m_list[--index]->m_content = s;
}

int todo_t::erase (int index) {
	if (index < 0 || index >= this->m_length) {
		//TODO: raise the Exception and catch it at the main
	}

	for (int i=0;i<this->m_length;i++) {
		if (i+1 == index) {
			this->m_list.erase(this->m_list.begin() + i);
			this->m_length--;
			return 1;
		}
	}
	return 0;
}

void todo_t::clear (void) {
	this->m_list.clear();
	this->m_length = 0;
}

void todo_t::cleanup (void) {
	for (auto i=this->m_list.begin(); i!=this->m_list.end();i++) {
		if ((*i)->m_state == true) {
			this->m_list.erase(i);
			this->m_length--;
		}
	}
}

std::string todo_t::toStringAll (void) {
	std::string ret;
	for (int i=0;i<this->m_length;i++) {
		ret += std::to_string(i+1);
		if (i < 9) ret += ".   ";
		else if (i < 99) ret += ".  ";
		else if (i < 999) ret += ". ";
		else ret += ".";
		ret += this->m_list[i]->toString();
		ret += "\n";
	}
	return ret;
}

std::string todo_t::toStringUndone (void) {
	std::string ret;
	for (int i=0;i<this->m_length;i++) {
		if (this->m_list[i]->m_state) continue;
		ret += std::to_string(i+1);
		if (i < 9) ret += ".   ";
		else if (i < 99) ret += ".  ";
		else if (i < 999) ret += ". ";
		else ret += ".";
		ret += this->m_list[i]->toString();
		ret += "\n";
	}
	return ret;
}

#endif
