rm output.txt
g++ main.cpp
./a.out a.txt b.txt c.txt output.txt
if [ $? -eq 0 ]
then
	vim output.txt
else
	echo Error: $?
fi
