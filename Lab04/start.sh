g++ -g fs.cpp -o a.out
valgrind ./a.out a.txt
echo Exit code: $?
