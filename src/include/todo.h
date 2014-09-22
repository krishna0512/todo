#ifndef _TODO_H
#define _TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "task.h"


class todo_t {
	private:
		std::vector<task_t*> m_list;
		size_t m_length;
	public:
		todo_t (void);
		~todo_t (void);

		// returns the size of the vector ie basically m_length;
		size_t size (void);

		// pushes the specified task at the end of the list.
		void push (task_t);

		// get the task by the index starts by 1
		task_t* getTask (unsigned int);

		// Sets the particular task as done.
		void setDone (unsigned int);

		// resets the particular task to undone.
		void setUndone (unsigned int);

		// Changes the content of the task.
		void modifyTask (unsigned int, std::string);

		// removes the task matching the decription.
		int erase (int);

		// Clears the whole todo list
		void clear (void);

		// Removes all the undone tasks
		void cleanup (void);

		std::string toStringAll (void);
		std::string toStringAllFormatted (void);
		std::string toStringUndoneFormatted (void);
		std::string toStringSingleFormatted (int);
};

#endif
