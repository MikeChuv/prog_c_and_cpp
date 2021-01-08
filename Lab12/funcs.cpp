#include "funcs.h"

bool is_latin(char val){
	if ((val >= 'A' && val <= 'Z') || (val >= 'a' && val <= 'z') ) return true;
	else return false;
}

bool is_punctuation(char val){
	const char points[] = "!,.-?:;[]{}()<>\"\'";
	bool fl = false;
	for (int i = 0; i < sizeof(points) && !fl; i++){
		if (points[i] == val) fl = true;
	}
	return fl;
}

bool is_even(int val){
	return val % 2 == 0;
}


bool is_number(char val){
	if (val >= '0' && val <= '9') return true;
	else return false;
}

bool is_positive(double val){
	return val > 0;
}