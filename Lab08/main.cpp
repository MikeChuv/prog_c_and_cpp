#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(int argc, char* argv[]){

	// string literal constructor
	String s1;
	s1.print();
	printf("S1 length = %d\n", s1.length());

	
	String s2 = "Hello World!";
	printf("S2 length = %d\n", s2.length());

	// change n-th char
	s2.print();
	int n;
	printf("Value = ");
	char c = getchar();
	printf("Index to change = ");
	scanf("%d", &n);
	s2.change_char(n, c);
	s2.print();

	// copy constructor
	String s3(s2, 5);
	s3.print();

	// double to string constructor
	String s4 = 5.14167;
	s4.print();

	// string to double conversion
	String s5 = "-2.71";
	double value = s5;
	printf("value = %lf\n", value);

	String s6 = value;
	s6.print();

	return 0;
}
