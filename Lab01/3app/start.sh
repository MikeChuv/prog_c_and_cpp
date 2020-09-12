rm output.txt
g++ -c -Wall -pedantic unit.cpp main.cpp
g++ -o a.out unit.o main.o
./a.out a.txt b.txt c.txt output.txt
if [ $? -eq 0 ]
then
	vim output.txt
else
	echo Exit code: $?
fi
