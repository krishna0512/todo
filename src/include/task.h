
#ifndef _TASK_H
#define _TASK_H

#include <string>
#include <stdio.h>
#include <stdlib.h>

class task_t {
	public:
		// false --> Undone
		// true --> Done
		bool m_state;
		std::string m_content;
		size_t m_size;

		task_t (void);
		task_t (std::string, bool);
		// This parses the input of format to the task.
		// format: 1.   [ ] First Todo task
		task_t (std::string);
		~task_t (void);

		std::string toString (void);

		// Checks if 2 tasks are identical
		bool equals (task_t*);
};

#endif
