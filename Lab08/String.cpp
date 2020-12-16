#include "String.h"
#include <cmath>
#include <stdio.h>

// returns length of a string (without \0)
int String::length() const{ return len;
}


// get n-th char from string
char String::get_char(int n) const {
	if (n > len){
		return 0;
	}
	return data[n];
}

void String::print() const{
	/*
	if (len == 0){
		printf("String is empty");
	}
	*/
	for (int i = 0; i < len; i++){
		printf("%c", data[i]);
	}
	printf("\n");
}


void String::change_char(int n, char c){
	data[n] = c;
}



// one parameter + default coustructor 
String::String(const char* in){
	int in_size = 0;
	while(in[in_size] != '\0') in_size++;
	if (in_size != 0){	
		allocate(in_size + sizeof('\0'));
		for(int i = 0; i < in_size; i++){
		data[i] = in[i];
		}
		data[in_size] = '\0';
	}
	len = in_size;
}


// copy constructor
String::String(const String& source, int n){
	allocate(n + sizeof('\0'));
	int end = n < source.length() ? n : source.length();
	for(int i = 0; i < end; i++){
		data[i] = source.get_char(i);
	}
	data[n] = '\0';
	len = n;
}


// double to string constructor
String::String(double number){
	double fractpart, intpart;
	fractpart = modf(number, &intpart);
	int sign = intpart < 0 ? -1 : 1;
	int i_intpart = (int)intpart * sign;
	int intpart_size = ceil(log10(intpart * sign));
	int tolerance = 7;
	allocate(sign < 0 ? intpart_size + tolerance + 3 : intpart_size + tolerance + 2);
	len = sign < 0 ? intpart_size + tolerance + 2 : intpart_size + tolerance + 1;
	
	// detecting sign
	int counter = 0;	
	int start = 0;
	if (sign < 0){
		data[0] = '-';
		start = 1;
		counter = 1;
	}
	// converting integral part
	for (int i = start; intpart_size != 0; i++){
		data[i] = (i_intpart / (int)pow(10, intpart_size - 1)) | 0x30;
		i_intpart = i_intpart % (int)pow(10, intpart_size - 1);
		intpart_size--;
		counter++;
	}

	data[counter++] = '.';

	// converting fractional part
	int i_fracpart = (int)(fractpart * pow(10, tolerance)) * sign;
	for (int i = counter; (i < len) && (tolerance >= 0); i++){
		data[i] = (i_fracpart / (int)pow(10, tolerance - 1)) | 0x30;
		i_fracpart = i_fracpart % (int)pow(10, tolerance - 1);
		tolerance--;
	}
	data[len] = '\0';
}


String::String(int size){
	if (size != 0){
		allocate(size + sizeof('\0'));
	}
	len = size;
}


// destructor
String::~String(){
	if (len != 0){
		delete [] data;
	}
	//printf("DESTROYED\n");
}


// convert operator string to double
String::operator double () const {
	int sign = data[0] == '-' ? -1 : 1;
	int start = sign == -1 ? 1 : 0;

	// finding dot position
	int i = start;
	while ( data[i] != '.') i++;
	int dot_pos = i;

	// converting integral part
	double intpart = 0;
	for(int j = start; j < dot_pos; j++){
		intpart += (data[j] & 0x0F) * pow(10, dot_pos - j - 1);
	}

	// converting fractional part
	double fractpart = 0;
	for(int j = dot_pos + 1; j <= len; j++){
		fractpart += (data[j] & 0x0F) * pow(10, len - j - 1);
	}
	fractpart /= pow(10, len - dot_pos - 1);

	return sign * (intpart + fractpart);
}


// memory allocation
void String::allocate(int size){
	data = new char [size];	
}


