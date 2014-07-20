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
		void push (task_t*);

		// get the task by the index starts by 1
		task_t* getTask (unsigned int);

		// removes the task matching the decription.
		int erase (task_t*);

		// Clears the whole todo list
		void clear (void);

		// Removes all the undone tasks
		void cleanup (void);

		std::string toString (void);
};

#endif
