#include <dlfcn.h>
#include <stdio.h>


#define DYN

#ifndef DYN
 #include "insertLib.h"
#endif

int main(int argc, char* argv[]){

	FILE* input_file = fopen(argv[1], "r");
	int mss, s1s, s2s;

	#ifdef DYN
	
	void* lib = dlopen("insertLib.so", RTLD_LAZY);
	while(!lib){
		printf("Cannot reach \"insertLib.so\". Try again\n");
		int c = getchar();
		lib = dlopen("insertLib.so", RTLD_LAZY);
	}

	char*(*readfn)(FILE*, int, int&, int&);
	void(*compare_loop)(char*&, int, char*, char*, int&, int, int, int&, int&);
	void(*print_string)(char*);

	readfn = (char*(*) (FILE*, int, int&, int&))dlsym(lib, "readfn");
	compare_loop = (void(*) (char*&, int, char*, char*, int&, int, int, int&, int&))dlsym(lib, "compare_loop");
	print_string = (void(*) (char*))dlsym(lib, "print_string");

	#endif
	int capacity = 10;
	char* mystring = readfn(input_file, 1, mss, capacity);
	int reserved = capacity;
	printf("Subs 1 = ");
	char* subs1 = readfn(input_file, 0, s1s, capacity);
	printf("Subs 2 = ");
	char* subs2 = readfn(input_file, 0, s2s, capacity);
	compare_loop(mystring, 0, subs1, subs2, mss, s1s, s2s, reserved, capacity);
	print_string(mystring);
	fclose(input_file);
	delete [] mystring;
	delete [] subs1;
	delete [] subs2;

	#ifdef DYN
	dlclose(lib);
	#endif
	return 0;
}


