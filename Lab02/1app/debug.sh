rm output.txt
g++ -g3 unit_static.cpp unit_dynamic.cpp main.cpp 
g++ -o0 a.out unit_static.o unit_dynamic.o main.o
gdb ./a.out

if [ $? -eq 0 ]
then
	vim output.txt
	echo Exit code: $?
else 
	echo Exit code: $?
fi
