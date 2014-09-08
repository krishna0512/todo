CC = g++
NAME = todo
OPT_DEVEL = -std=c++0x -Wall -Wno-sign-compare -g -O0
OPT = -std=c++0x -Wall -Wno-sign-compare -Ofast -flto -funroll-loops

$(NAME): todo.o task.o main.o utility.o
	$(CC) -o $(NAME) task.o todo.o main.o utility.o $(OPT_DEVEL)

todo.o: todo.cpp include/todo.h
	$(CC) -c -o todo.o todo.cpp $(OPT_DEVEL)

task.o: include/task.h task.cpp
	$(CC) -c -o task.o task.cpp $(OPT_DEVEL)

utility.o: include/utility.h utility.cpp
	$(CC) -c -o utility.o utility.cpp $(OPT_DEVEL)

main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(OPT_DEVEL)

clear:
	rm -rf *.o $(NAME)

clean:
	rm -rf *.o $(NAME)

install: $(NAME)
	@echo "Installing Program.."
	@install --mode=755 todo /usr/bin

uninstall:
	@rm -r /usr/bin/todo 2>/dev/null
