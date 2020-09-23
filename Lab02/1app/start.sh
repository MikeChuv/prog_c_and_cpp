g++ -c -Wall -pedantic unit_static.cpp 
g++ -c -Wall -pedantic unit_dynamic.cpp
g++ -c -Wall -pedantic main.cpp
g++ -o a.out unit_static.o unit_static.o main.o
./a.out a.txt b.txt output.txt $1
echo Exit code: $?
