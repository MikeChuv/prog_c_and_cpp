g++ main.cpp
./a.out log.txt
if [ $? -eq 0 ]
then
	vim log.txt
else
	echo Exit code: $?
fi
