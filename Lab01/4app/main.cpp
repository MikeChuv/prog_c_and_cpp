#include <stdio.h>
#include <stdlib.h>
#include "unit.h"


int main(int argc, char *argv[]){
	double *a = nullptr;
       	double *b = nullptr;
 	double *c = nullptr;
	int am_a, am_b, am_c, max;
	double mynumber;
	int size_a, size_b, size_c; // array sizes
	int main_flag = 0; // err flag (exit code)


	// number entry
	printf("Введите число: ");
	if (scanf("%lf", &mynumber) < 1){
		printf("Неверный формат\n");
		main_flag = 1;
	}


	// array entry
	// array_input function allocates memory!!! don't forget delete[]
	a = array_input(&size_a, argv[1]);
	b = array_input(&size_b, argv[2]);
	c = array_input(&size_c, argv[3]);

	// checking if values in files are valid
	if (!main_flag && a && b && c){


		// counting numbers for each array
		am_a = count(a, size_a, mynumber);
		am_b = count(b, size_b, mynumber);
		am_c = count(c, size_c, mynumber);
	
		printf("a: %d \nb: %d \nc: %d \n", am_a, am_b, am_c);

		// finding max of counted values
		max = am_a;
		if (am_b > max) max = am_b;
		if (am_c > max) max = am_c;

		// output
		if (max == 0){
			printf("В массивах нет чисел, меньше (%5.2lf)\n", mynumber);	
		}
		else{
			if (am_a == max){
				printf("Массив A, кол-во: (%d)\n", max);
			}	
			if (am_b == max){
				printf("Массив B, кол-во: (%d)\n", max);
			}
			if (am_c == max){
				printf("Массив C, кол-во: (%d)\n", max);
			}

		}
		main_flag = 0;

	}
	else{
		main_flag = 1;
	}
	
	if (a) delete[] a;
	if (b) delete[] b;
	if (c) delete[] c;

	return main_flag;

}


