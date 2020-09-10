g++ -c -Wall unit.cpp main.cpp
g++ -o a.out unit.o main.o
./a.out a.txt b.txt c.txt
echo Exit code: $?
