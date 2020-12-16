#include "String.h"
#include "Exceptions.h"
#include <cmath>
#include <stdio.h>

// returns length of a string (without \0)
int String::length() const{
	return len;
}


// get n-th char from string
char String::get_char(int n) const {
	if (n > len || n < 0)
		throw IndexOutOfRange(n, "get_char()");
	else
		return data[n];
}

void String::print() const{
	for (int i = 0; i < len; i++){
		printf("%c", data[i]);
	}
	printf("\n");
}


void String::change_char(int n, char c){
	if (n > len || n < 0) 
		throw IndexOutOfRange(n, "change_char()");
	else
		data[n] = c;
}



// one parameter + default coustructor 
String::String(const char* in){
	int in_size = 0;
	while(in[in_size] != '\0') in_size++;
	if (in_size > 5000) throw BadAlloc(in_size, "\"String\" constuctor [0, 5000)");
	else{
		if (in_size != 0){
			allocate(in_size + sizeof('\0'));
			for(int i = 0; i < in_size; i++){
				data[i] = in[i];
			}
			data[in_size] = '\0';
		}
		len = in_size;
	}
}


// copy constructor
String::String(const String& source, int n){
	if (n > 5000 || n < 0) throw BadAlloc(n, "\"Copy\" constuctor [0, 5000)");
	else{
		if (n != 0){
			allocate(n + sizeof('\0'));
			int end = n < source.len ? n : source.len;
			for(int i = 0; i < end; i++){
				data[i] = source[i];
			}
			data[n] = '\0';
		}
		len = n;
	}
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
	if (size > 5000 || size < 0) throw BadAlloc(size, "\"Size\" constuctor [0, 5000)");
	else{
		allocate(size + sizeof('\0'));
		len = size;
	}
}


// destructor
String::~String(){
	if (len != 0){
		delete [] data;
	}
	//printf("LOLKEK\n");
}

/*
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
*/

String & String::operator = (const String& s){
	this -> ~String();
	allocate(s.len);	
	for(int i = 0; i < s.len; i++){
		data[i] = s[i];
	}
	len = s.len;
	return *this;
}



bool operator < (const String& s1, const String& s2)  {
	bool result;
	if (s1.len != s2.len){
		result = s1.len < s2.len ? true : false;
	}
	else{
		for (int i = 0; i < s2.len; i++){
			result = s1[i] < s2[i] ? true : false;
		}
	}
	return result;
}



bool operator > (const String& s1, const String& s2)  {
	bool result;
	if (s1.len != s2.len){
		result = s1.len > s2.len ? true : false;
	}
	else{
		for (int i = 0; i < s2.len; i++){
			result = s1[i] > s2[i] ? true : false;
		}
	}
	return result;
}


bool operator == (const String& s1, const String& s2)  {
	bool flag = true;
	if (s1.len != s2.len){
		flag = false;
	}
	else{
		for(int i = 0; i < s2.len; i++){
			flag = s1[i] == s2[i] ? true : false; 
		}
	}
	return flag;
}

bool operator != (const String& s1, const String& s2) {
	return s1 == s2 ? false : true;
}

char & String::operator [] (int index){
	if (index > len || index < 0) 
		throw IndexOutOfRange(index, "operator []");
	else
		return data[index];
}

const char & String::operator [] (int index) const{
	if (index > len || index < 0) 
		throw IndexOutOfRange(index, "operator [] const");
	else
		return data[index];
}


int String::compare(char* mystring, char* sub1) {
	int result = 0;
	if ((*sub1 == *mystring) && (*sub1 != '\0') && (*mystring != '\0')) result = compare(mystring + 1, sub1 + 1);
	return 1 + result;
}

void String::operator += (char c){
	String new_string(len + 1);
	for (int i = 0; i < len; i++){
		new_string[i] = data[i];
	}
	new_string[len] = c;
	new_string[len + 1] = '\0';
	*this = new_string;
}


void String::operator += (const String& s){
	String new_string(len + s.len);
	for (int i = 0; i < len; i++){
		new_string[i] = data[i];
	}
	for (int i = len; i < len + s.len; i++){
		new_string[i] = s.data[i - len];
	}
	new_string[len + s.len] = '\0';
	*this = new_string;
}

// memory allocation
void String::allocate(int size){
	data = new char [size];	
}


String operator + (const String& s1, const String& s2){
	int size = s1.len + s2.len;
	String new_string(size);
	for (int i = 0; i < s1.len; i++){
		new_string[i] = s1[i];
	}
	for (int i = 0; i < s2.len; i++){
		new_string[i + s1.len] = s2[i];
	}
	new_string[s1.len + s2.len] = '\0';
	return new_string;
}

String operator - (const String& s1, const String& s2) {
	int counter = 0;
	int* idx = new int[s1.len];
	for (int i = 0; i < s1.len; i++){
		int shift = String::compare(s1.data + i, s2.data);
		if (shift - 1 == s2.len) {
			idx[counter] = i;
			counter++;
		}
	}
	int new_size = s1.len - (counter * s2.len);
	String new_string(new_size);
	int last_x = 0; //in old
	int new_index = 0; //in new
	if (counter == 0){
		for(int i = 0; i < new_size; i++){
			new_string[i] = s1[i];
		}
	}
	else{
		for (int j = 0; j < counter; j++){
			for(int i = last_x; i < idx[j]; i++){
				new_string[new_index] = s1.data[i];
				new_index++;
			}
			last_x = idx[j] + s2.len;
		}
		if ((idx[counter - 1] + s2.len) != s1.len){
			for (int i = idx[counter - 1] + s2.len; i < s1.len; i++){
				new_string[new_index] = s1.data[i];
				new_index++;
			}
		}
	}
	if (new_size != 0){
		new_string[new_size] = '\0';
	}
	delete [] idx;
	return new_string;
}


