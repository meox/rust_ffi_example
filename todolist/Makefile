GPP=g++
GCC=gcc
CFLAGS=-O2 -Wall -Werror

todolist.o: todolist.c todolist.h
	${GCC} -c ${CFLAGS} -fpic todolist.c

libtodolist.so: todolist.o
	${GCC} -shared -o libtodolist.so todolist.o

todo_app: libtodolist.so todo_app.cpp
	${GPP} ${CFLAGS} todo_app.cpp -Wl,-rpath,. -ltodolist -L . -o todo_app

clean:
	rm -rf *.o libtodolist.so todo_app
.PHONY : all
all : todo_app
