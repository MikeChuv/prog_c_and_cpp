#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

volatile int capacity = 10;

void compare(FILE* input, char* sub1, char* sub2){
	char ch = fgetc(input);
	int result = 0;
	if (*sub1 == ch){
		printf("%c", ch);
		compare(input, sub1 + 1, sub2);
	}
	else if (*sub1 == '\0')
		printf("%s%c", sub2, ch);
	else if (ch != EOF)
		printf("%c", ch);
	return;
}

void read(FILE* input){
	while(!feof(input)){
		char this_char;
		fscanf(input, "%c", &this_char);
		printf("%c", this_char);
	}
	printf("\n");
	return;
}

char* readsub(){
	int flag = 0;
	char* subs = new char[capacity];
	for(int i = 0; i < capacity && !flag; i++){
		char ch = getchar();
		subs[i] = (ch == '\n') ? '\0' : ch;
		flag = (ch == '\n') ? 1 : 0;
	}
//	while ((getchar()) != '\n');
	return subs;
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
	while(!feof(input_file))
		compare(input_file, subs1, subs2);
	delete [] subs1;
	delete [] subs2;
	return 0;
}




