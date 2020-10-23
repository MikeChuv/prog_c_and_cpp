#include <stdio.h>
#include "unit.h"

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

