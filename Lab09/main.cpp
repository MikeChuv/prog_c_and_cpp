#include <stdio.h>
#include <stdlib.h>
#include "String.h"


int main(int argc, char* argv[]){

	// string literal constructor
	String s1;
	printf("S1 length = %d\n", s1.length());

	
	String s2 = "Hello World!";
	printf("S2 length = %d\n", s2.length());

	// change n-th char
	s2.print();
	s2.change_char(5, '%');
	printf("s2 = ");
	s2.print();

	// copy constructor
	String s3(s2, 5);
	printf("s3 = ");
	s3.print();

	// double to string constructor
	String s4 = -8.74169;
	printf("s4 = ");
	s4.print();

	s4 += '@';
	printf("s4 + @ = ");
	s4.print();

	s4 = s3 + s2;
	printf("s3 + s2 = ");
	s4.print();

	String s6 = "Hell";
	s4 = s4 - s6;
	printf("s4 - s6 = ");
	s4.print();

	// string to double conversion
	double value;
	String s5 = "-2.71";
	value = s5;
	printf("value = %lf\n", value);

	
	String s7 = "ABD";
	String s8 = "ABC";
	printf("%s", s7 == s8 ? "true\n" : "false\n");


	s7 += s8;
	s7.print();
	// reading from keyboard
	//String s6 = input();
	//s6.print();
	//printf("s6 length = %d\n", s6.length());


	return 0;
}
