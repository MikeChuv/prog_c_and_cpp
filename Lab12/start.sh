#!/bin/zsh
g++ -c main.cpp funcs.cpp tasks.cpp Exceptions.cpp
g++ -o a.out main.o funcs.o tasks.o Exceptions.o
# valgrind ./a.out
valgrind ./a.out list1.txt list2.txt deque1.txt deque2.txt 2> log.txt
echo Exit code: $?
