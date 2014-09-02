CC = g++
NAME = todo
OPT = -std=c++0x -Wall -Wno-sign-compare -g

$(NAME): todo.o task.o main.o utility.o
	$(CC) -o $(NAME) task.o todo.o main.o utility.o $(OPT)

todo.o: todo.cpp include/todo.h
	$(CC) -c -o todo.o todo.cpp $(OPT)

task.o: include/task.h task.cpp
	$(CC) -c -o task.o task.cpp $(OPT)

utility.o: include/utility.h utility.cpp
	$(CC) -c -o utility.o utility.cpp $(OPT)

main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(OPT)

clear:
	rm -rf *.o $(NAME)

clean:
	rm -rf *.o $(NAME)

install: $(NAME)
	@echo "Installing Program.."
	@install --mode=755 todo /usr/bin

uninstall:
	@rm -rf /usr/bin/todo 2>/dev/null
