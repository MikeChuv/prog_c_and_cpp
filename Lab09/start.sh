g++ -c -Wall -pedantic String.cpp utils.cpp main.cpp
g++ -o a.out utils.o String.o main.o
valgrind --leak-check=full ./a.out
# ./a.out
# --read-var-info=yes 
echo Exit code: $?
