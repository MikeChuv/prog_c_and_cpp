rm output.txt
g++ -c -Wall -pedantic unit.cpp main.cpp
g++ -o a.out unit.o main.o
valgrind ./a.out a.txt b.txt c.txt output.txt $1

if [ $? -eq 0 ]
then
	vim output.txt
else
	echo Exit code: $?
fi
