CC = g++
NAME = todo
OPT_DEVEL = -std=c++0x -Wall -Wno-sign-compare -g -O0
OPT = -std=c++0x -Wall -Wno-sign-compare -Ofast -flto -funroll-loops

OBJ=todo
PREFIX=$(DESTDIR)/usr
BINDIR=$(PREFIX)/bin

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
	rm -f *.o $(NAME)

clean:
	rm -f *.o $(NAME)

ofast:
	$(CC) $(OPT) -c todo.cpp
	$(CC) $(OPT) -c task.cpp
	$(CC) $(OPT) -c utility.cpp
	$(CC) $(OPT) -c main.cpp
	$(CC) -o $(NAME) task.o todo.o main.o utility.o $(OPT)

install: $(NAME)
	@echo "Installing Program.."
	@mkdir -p $(BINDIR) 2>/dev/null
	@install --mode=755 $(OBJ) $(BINDIR)/$(TARGET) || echo "\033[31m FAILED. \033[39m Try "make PREFIX=~ install" ?"

uninstall:
	@rm -r $(BINDIR)/$(OBJ) 2>/dev/null
