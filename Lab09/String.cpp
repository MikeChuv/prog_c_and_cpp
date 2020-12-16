#include "String.h"
#include <cmath>
#include <stdio.h>

// returns length of a string (without \0)
int String::length() const{
	return len;
}


// get n-th char from string
char String::get_char(int n) const {
	if (n > len){
		return 0;
	}
	return data[n];
}

void String::print() const{
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
		data[i] = source[i];
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
		intpart_size --;
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
	//printf("LOLKEK\n");
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



String & String::operator = (const String& s){
	this -> ~String();
	allocate(s.length());	
	for(int i = 0; i < s.length(); i++){
		data[i] = s[i];
	}
	len = s.length();
	return *this;
}



bool String::operator < (const String& s) const {
	bool result;
	if (length() != s.length()){
		result = length() < s.length() ? true : false;
	}
	else{
		for (int i = 0; i < s.length(); i++){
			result = data[i] < s[i] ? true : false;
		}
	}
	return result;
}



bool String::operator > (const String& s) const {
	bool result;
	if (length() != s.length()){
		result = length() > s.length() ? true : false;
	}
	else{
		for (int i = 0; i < s.length(); i++){
			result = data[i] > s[i] ? true : false;
		}
	}
	return result;
}


bool String::operator == (const String& s) const {
	bool flag = true;
	if (length() != s.length()){
		flag = false;
	}
	else{
		for(int i = 0; i < s.length(); i++){
			flag = data[i] == s[i] ? true : false; 
		}
	}
	return flag;
}

bool String::operator != (const String& s) const{
	return *this == s ? false : true;
}

char & String::operator [] (int index){
	return data[index];
}

const char & String::operator [] (int index) const{
	return data[index];
}

String String::operator + (const String& s) const{
	int size = length() + s.length();
	String new_string(size);
	for (int i = 0; i < length(); i++){
		new_string[i] = data[i];
	}
	for (int i = 0; i < s.length(); i++){
		new_string[i + length()] = s[i];
	}
	new_string[length() + s.length()] = '\0';
	return new_string;
}


int String::compare(char* mystring, char* sub1) const{
	int result = 0;
	if ((*sub1 == *mystring) && (*sub1 != '\0') && (*mystring != '\0')) result = compare(mystring + 1, sub1 + 1);
	return 1 + result;
}

String String::operator - (const String& s) const{
	int counter = 0;
	int* idx = new int[length()];
	for (int i = 0; i < length(); i++){
		if (compare(data + i, s.data) != 1) {
			idx[counter] = i;
			counter++;
		}
	}
	int new_size = length() - (counter * s.length());
	String new_string(new_size);
	int last_x = 0; //in old
	int new_index = 0; //in new
	for (int j = 0; j < counter; j++){
		for(int i = last_x; i < idx[j]; i++){
			new_string[new_index] = data[i];
			new_index++;
		}
		last_x = idx[j] + s.length();
	}
	if ((idx[counter - 1] + s.length()) != length()){
		for (int i = idx[counter - 1] + s.length(); i < length(); i++){
			new_string[new_index] = data[i];
			new_index++;
		}
	}
	new_string[new_size] = '\0';
	delete [] idx;
	return new_string;
}

void String::operator += (char c){
	String new_string(length() + 1);
	for (int i = 0; i < length(); i++){
		new_string[i] = data[i];
	}
	new_string[length()] = c;
	new_string[length() + 1] = '\0';
	*this = new_string;
}


void String::operator += (const String& s){
	String new_string(length() + s.length());
	for (int i = 0; i < length(); i++){
		new_string[i] = data[i];
	}
	for (int i = length(); i < length() + s.length(); i++){
		new_string[i] = s.data[i - length()];
	}
	new_string[length() + s.length()] = '\0';
	*this = new_string;
}

// memory allocation
void String::allocate(int size){
	data = new char [size];	
}

