#include <stdio.h>

volatile int capacity = 10;

void compare(FILE* input, char* sub1, char* sub2){
	char ch = fgetc(input);
	if (*sub1 == ch){
		printf("%c", ch);
		compare(input, sub1 + 1, sub2);
	}
	else if (*sub1 == '\0') printf("%s%c", sub2, ch);
	else if (ch != EOF) printf("%c", ch);
	return;
}

void read(FILE* input){
	while(!feof(input)){
		char this_char = fgetc(input);
		(this_char != EOF) ? printf("%c", this_char) : printf("\n");
	}
	return;
}

char* resize(char* subs){
	char* result = new char [capacity*2];
	for(int i = 0; i < capacity; i++) result[i] = subs[i];	
	delete [] subs;
	capacity *= 2;
	return result;
}

char* readsub(){
	char* subs = new char[capacity]; char ch; int i = 0;
	do{
		ch = getchar();
		subs[i] = (ch == '\n') ? '\0' : ch; i++;
		if (i == capacity)	subs = resize(subs);
	}
	while(ch != '\n');
	return subs;
}

void compare_loop(FILE* input, char* subs1, char* subs2){	
	while(!feof(input)) compare(input, subs1, subs2);
}

int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	char *subs1, *subs2;
	read(input_file);
	printf("Subs 1 = ");
	subs1 = readsub();
	printf("Subs 2 = ");
	subs2 = readsub();
	fseek(input_file, 0, SEEK_SET);
	compare_loop(input_file, subs1, subs2);
	fclose(input_file);
	delete [] subs1;
	delete [] subs2;
	return 0;
}

