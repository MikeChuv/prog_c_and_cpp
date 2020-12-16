#include "insertLib.h"


int compare(char* mystring, char* sub1){
	int result = 0;
	if ((*sub1 == *mystring) && (*sub1 != '\0') && (*mystring != '\0')) result = compare(mystring + 1, sub1 + 1);
	return 1 + result;
}

char* resize(char* subs, int& capacity){
	char* result = new char [capacity*2];
	for(int i = 0; i < capacity; i++) result[i] = subs[i];	
	delete [] subs;
	capacity *= 2; 
	return result; 
}

extern "C" char* readfn(FILE* input, int mode, int &chars, int& capacity){
	char* mystring = new char [capacity]; char ch; int i = 0;
	do{
		ch = mode ? fgetc(input) : getchar();
		if (mode && (ch != EOF)) printf("%c", ch);
		mystring[i] = ( (mode && ( (ch == EOF)||(ch == '\n') ) ) || (!mode && ch == '\n')) ? '\0' : ch; i++;
		if (i == capacity) mystring = resize(mystring, capacity);
	}
	while(  (mode && !feof(input))  ||  (!mode && (ch != '\n'))  );
	chars = i - 1;
	return mystring;
}

// рекурсивно перемещаем хвост mode = 1, и вставляем подстроку mode = 0;
void change(char*& mystring, int offset, char* subs2, int s1s, int s2s, int j, int mode){
	if (   (mode && (j >= offset + s1s)) || (!mode && (j < s2s))   ){
		int start = mode ? j + s2s : j + s1s + offset;
		mystring[start] = mode ? mystring[j--] : subs2[j++];
		change(mystring, offset, subs2, s1s, s2s, j, mode);
	}
	return;
}

// вставка подстроки
void s2_to_ms(char*& mystring, int offset, char* subs2, int& mss, int s1s, int s2s){
	change(mystring, offset, subs2, s1s, s2s, mss, 1);	
	mss += s2s;
	change(mystring, offset, subs2, s1s, s2s, 0, 0);
	return;
}

extern "C" void compare_loop(char*& mystring, int offset, char* subs1, char* subs2, int& mss, int s1s, int s2s, int& size, int& capacity){
	int shift = 0;
	if(*mystring != '\0' && offset <= mss) {
		shift = compare(mystring + offset, subs1); 
		if ( (shift - 1) == s1s){
			if (size - mss > s2s) s2_to_ms(mystring, offset, subs2, mss, s1s, s2s);
			else{
				mystring = resize(mystring, capacity);
				size = capacity;
				s2_to_ms(mystring, offset, subs2, mss, s1s, s2s);
			}
			compare_loop(mystring, offset + shift + s2s + 1, subs1, subs2, mss, s1s, s2s, size, capacity);
		}
		else compare_loop(mystring, offset + shift, subs1, subs2, mss, s1s, s2s, size, capacity);
	}
	return;
}

extern "C" void print_string(char* mystring){
	for(int i = 0; mystring[i] != '\0'; i++) printf("%c", mystring[i]);
	printf("\n");
	return;
}

