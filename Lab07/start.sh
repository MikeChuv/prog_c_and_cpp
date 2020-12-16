#!/bin/zsh

g++ -c -Wall -pedantic insertLib.cpp -fpic
g++ insertLib.o -shared -o insertLib.so
g++ -c -Wall -pedantic main.cpp -o main.o

# статика
# g++ -o a.out main.o -L. -ldl insertLib.so

# флаг -ldl для возможности динамической связи
g++ -o a.out main.o -L. -ldl

# . ~/.zshrc

# sudo cp insertLib.so /usr/lib
# valgrind ./a.out a.txt
ldd a.out
# sudo rm /usr/lib/insertLib.so

# rm main.o insertLib.o insertLib.so

echo Exit code: $?

