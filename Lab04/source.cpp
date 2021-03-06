#include <stdio.h>

volatile int capacity = 10;

int compare(char* mystring, char* sub1){
	int result = 0;
	if ((*sub1 == *mystring) && (*sub1 != '\0') && (*mystring != '\0')) result = compare(mystring + 1, sub1 + 1);
	return 1 + result;
}

char* resize(char* subs){
	char* result = new char [capacity*2];
	for(int i = 0; i < capacity; i++) result[i] = subs[i];	
	delete [] subs;
	capacity *= 2; 
	return result; 
}

char* readfn(FILE* input, int mode, int &chars){
	char* mystring = new char [capacity]; char ch; int i = 0;
	do{
		ch = mode ? fgetc(input) : getchar();
		if (mode && (ch != EOF)) printf("%c", ch);
		mystring[i] = ( (mode && ( (ch == EOF)||(ch == '\n') ) ) || (!mode && ch == '\n')) ? '\0' : ch; i++;
		if (i == capacity) mystring = resize(mystring);
	}
	while(  (mode && !feof(input))  ||  (!mode && (ch != '\n'))  );
	chars = i - 1;
	return mystring;
}


void s2_to_ms(char*& mystring, char* subs2, int& mss, int s1s, int s2s, int i){
	for(int j = mss; j >= i + s1s; j--) mystring[j + s2s] = mystring[j]; 
	mss += s2s;
	for(int j = 0; j < s2s; j++) mystring[i + s1s + j] = subs2[j];
	return;
}

void compare_loop(char*& mystring, char* subs1, char* subs2, int& mss, int s1s, int s2s, int& size){
	int i = 0; int shift = 0;
	while(mystring[i] != '\0') {
		shift = compare(mystring + i, subs1); 
		if ( (shift - 1) == s1s){
			if (size - mss > s2s) s2_to_ms(mystring, subs2, mss, s1s, s2s, i);
			else{
				mystring = resize(mystring);
				size = capacity;
				s2_to_ms(mystring, subs2, mss, s1s, s2s, i);
			}
			i += shift + s2s;
		}
		else{ i += shift; }
	}
	return;
}

void print_string(char* mystring){
	int i = 0;
	while(mystring[i] != '\0') printf("%c", mystring[i++]);
	printf("\n");
	return;
}

int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	int mss, s1s, s2s;
	char* mystring = readfn(input_file, 1, mss);
	int reserved = capacity;
	printf("Subs 1 = ");
	char* subs1 = readfn(input_file, 0, s1s);
	printf("Subs 2 = ");
	char* subs2 = readfn(input_file, 0, s2s);
	compare_loop(mystring, subs1, subs2, mss, s1s, s2s, reserved);
	print_string(mystring);
	fclose(input_file);
	delete [] mystring;
	delete [] subs1;
	delete [] subs2;
	return 0;
}

