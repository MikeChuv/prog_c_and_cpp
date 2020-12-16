g++ -c Exceptions.cpp String.cpp utils.cpp main.cpp
# -Wall -pedantic
g++ -o a.out utils.o Exceptions.o String.o main.o
valgrind --leak-check=full ./a.out
# ./a.out
# --read-var-info=yes 
rm a.out
rm String.o utils.o main.o
echo Exit code: $?
