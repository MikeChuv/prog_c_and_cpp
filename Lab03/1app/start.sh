rm out.txt out.log b.bin
g++ -c unit.cpp utils.cpp main.cpp
g++ -o a.out unit.o utils.o main.o
./a.out a.txt b.bin out.txt out.log
echo Exit code: $?
