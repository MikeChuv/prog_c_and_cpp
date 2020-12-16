#include "utils.h"
#include <stdio.h>

char* resize(char* subs, int& capacity){
	char* result = new char [capacity*2];
	for(int i = 0; i < capacity; i++) result[i] = subs[i];	
	delete [] subs;
	capacity *= 2; 
	return result; 
}

String input(){
	int capacity = 10;
	char* mystring = new char [capacity]; 
	char ch; 
	int i = 0;
	do{
		ch = getchar();
		mystring[i] = ch == '\n' ? '\0' : ch; 
		i++;
		if (i == capacity) mystring = resize(mystring, capacity);
	}
	while(ch != '\n');
	String result = mystring;
	delete [] mystring;
	return result;
}

