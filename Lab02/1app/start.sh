rm output.txt
g++ -c -Wall -pedantic unit_static.cpp 
g++ -c -Wall -pedantic unit_dynamic.cpp
g++ -c -Wall -pedantic main.cpp
g++ -o a.out unit_static.o unit_dynamic.o main.o
valgrind ./a.out a.txt b.txt output.txt $1

if [ $? -eq 0 ]
then
	vim output.txt
	echo Exit code: $?
else 
	echo Exit code: $?
fi
