#pragma once
#include <stdio.h>


// есть вызов
extern "C" char* readfn(FILE* input, int mode, int &chars, int& capacity);

// есть вызов
extern "C" void compare_loop(char*& mystring, int offset, char* subs1, char* subs2, int& mss, int s1s, int s2s, int& size, int& capacity);

// есть вызов
extern "C" void print_string(char* mystring);

