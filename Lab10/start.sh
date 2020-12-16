g++ -c -Wall -pedantic String.cpp utils.cpp main.cpp
g++ -o a.out utils.o String.o main.o
valgrind --leak-check=full --track-origins=yes ./a.out
# ./a.out
# --read-var-info=yes 
rm a.out
rm String.o utils.o main.o
echo Exit code: $?
