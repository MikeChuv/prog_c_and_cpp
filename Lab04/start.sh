g++ -c unit.cpp main.cpp 
g++ -o a.out unit.o main.o
valgrind ./a.out a.txt
echo Exit code: $?
