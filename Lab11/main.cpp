#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <iostream>

int main(int argc, char* argv[]){

	String s1;

	String s2 = "Hello World!";
	printf("S2 length = %d\n", s2.length());

	try{
		String s4(s2, -1);
		s4.print();
	}
	catch (const BadAlloc& exception){
		exception.print_error();
	}


	// change n-th char
	printf("s2 = ");
	s2.print();
	try{
		s2.change_char(40, '%');
	}
	catch (const IndexOutOfRange& exception){
		exception.print_error();
	}
	printf("s2 = ");
	s2.print();

	try{
		String s3(2000000);
		s3.print();
	}
	catch (const BadAlloc& exception) {
		exception.print_error();
	}

	return 0;
}
