#ifndef _TODO_CPP
#define _TODO_CPP

#include "include/todo.h"

todo_t::todo_t (void) {
	this->m_length = 0;
}

todo_t::~todo_t (void) {
	for (auto i = this->m_list.begin() ; i < this->m_list.end() ; i++)
		delete *i;
	this->m_list.clear();
}

size_t todo_t::size (void) {
	return this->m_length;
}

void todo_t::push (task_t task) {
	task_t *temp = new task_t(task);
	this->m_list.push_back (temp);
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

void todo_t::setUndone (unsigned int index) {
	if (index < 0 || index >= this->m_length) {
		//TODO: raise the Exception and catch it at the main
	}

	this->m_list[--index]->m_state = false;
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
			delete this->m_list[i];
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
	for (auto i=this->m_list.begin(); i!=this->m_list.end();) {
		if ((*i)->m_state == true) {
			delete *i;
			this->m_list.erase(i);
			this->m_length--;
		}
		else {
			i++;
		}
	}
}

std::string todo_t::toStringAll (void) {
	std::string ret;
	for (int i=0;i<this->m_length;i++) {
		ret += std::to_string(i+1);
		if (i < 9) ret += ".  ";
		else if (i < 99) ret += ". ";
		else ret += ".";
		ret += this->m_list[i]->toString();
		ret += "\n";
	}
	return ret;
}

std::string todo_t::toStringAllFormatted (void) {
	std::string ret;
	for (int i=0;i<this->m_length;i++) {
		// blue color
		ret += "\x1b[34m";
		ret += std::to_string(i+1);
		if (i < 9) ret += ".  ";
		else if (i < 99) ret += ". ";
		else ret += ".";
		// reset color
		ret += "\x1b[0m";
		ret += this->m_list[i]->toStringFormatted();
		ret += "\n";
	}
	return ret;
}

std::string todo_t::toStringUndoneFormatted (void) {
	std::string ret;
	for (int i=0;i<this->m_length;i++) {
		if (this->m_list[i]->m_state) continue;
		// blue color
		ret += "\x1b[34m";
		ret += std::to_string(i+1);
		if (i < 9) ret += ".  ";
		else if (i < 99) ret += ". ";
		else ret += ".";
		// reset color.
		ret += "\x1b[0m";
		ret += this->m_list[i]->toStringFormatted();
		ret += "\n";
	}
	return ret;
}

std::string todo_t::toStringSingleFormatted (int index) {
	std::string ret;
	// blue color
	ret = "\x1b[34m"
		+ std::to_string(index)
		+ ".  "
		// reset color.
		+ "\x1b[0m"
		+ this->m_list[index-1]->toStringFormatted()
		+ "\n";
	return ret;
}

#endif
