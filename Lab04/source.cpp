#include <stdio.h>

volatile int capacity = 10;

int compare(char* mystring, char* sub1, char* sub2){
	int result = 0;
	if (*sub1 == *mystring){
		//printf("%c", *mystring);
		result = compare(mystring + 1, sub1 + 1, sub2);
	}
	else if (*sub1 == '\0') {
		//printf("%s%c", sub2, *mystring);
		// передвинуть хвост на s2s позиций и вставить нужные символы
	}
	//else //printf("%c", *mystring);
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
		(mode && (ch == EOF)) ? printf("\n") : printf("%c", ch);
		mystring[i] = ( (mode && (ch == EOF)) || (!mode && ch == '\n')) ? '\0' : ch; i++;
		if (i == capacity) mystring = resize(mystring);
	}
	while(  (mode && !feof(input))  ||  (!mode && (ch != '\n'))  );
	chars = i - 1;
	printf("Size = %d\n", chars);
	return mystring;
}

void compare_loop(char* mystring, char* subs1, char* subs2, int& mss, int s1s, int s2s, int& size){
	int i = 0; int shift = 0;	
	while(mystring[i] != '\0') {
		shift = compare(mystring + i, subs1, subs2); 
		if ( (shift - 1) == s1s){
			printf("\nInserting: s2s = %d\n", s2s);
			if (size - mss >= s2s){
				// вставить элементы	
				for(int j = mss + 1; j >= i + s1s; j--) mystring[j + s2s] = mystring[j]; 
				mss += s2s;
				for(int j = 0; j < s2s; j++) mystring[i + s1s + j] = subs2[j];
			}
			else{
				// расширяем и вставляем
			}
			printf("\nThey are equal\n free: %d\n", size - mss);
		}
		i += shift; 
	}
	i = 0;
	printf("\n");
	while(mystring[i] != '\0') printf("%c", mystring[i++]);
}

int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	char *mystring, *subs1, *subs2;
	int mss, s1s, s2s;
	mystring = readfn(input_file, 1, mss);
	int kek = capacity;
	printf("Kek = %d", kek);
	printf("Subs 1 = ");
	subs1 = readfn(input_file, 0, s1s);
	printf("Subs 2 = ");
	subs2 = readfn(input_file, 0, s2s);
	fseek(input_file, 0, SEEK_SET);
	compare_loop(mystring, subs1, subs2, mss, s1s, s2s, kek);
	fclose(input_file);
	delete [] mystring;
	delete [] subs1;
	delete [] subs2;
	return 0;
}

