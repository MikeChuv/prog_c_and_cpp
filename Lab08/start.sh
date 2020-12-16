g++ -c -Wall -pedantic String.cpp main.cpp
g++ -o a.out String.o main.o
valgrind --leak-check=full ./a.out
# ./a.out
# --read-var-info=yes 
echo Exit code: $?
