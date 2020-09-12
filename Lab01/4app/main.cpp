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

	FILE *output_file;

	// number entry
	printf("Введите число: ");
	if (scanf("%lf", &mynumber) < 1){
		printf("Неверный формат\n");
		main_flag = 1;
	}


	// array entry
	// array_input function allocates memory!!! don't forget delete[]
	a = array_input(size_a, argv[1]);
	b = array_input(size_b, argv[2]);
	c = array_input(size_c, argv[3]);

	// checking if values in files are valid
	if (!main_flag && a && b && c){


		print_array(size_a, a, argv[4], 'a');
		print_array(size_b, b, argv[4], 'b');
		print_array(size_c, c, argv[4], 'c');
		// counting numbers for each array
		am_a = count(a, size_a, mynumber);
		am_b = count(b, size_b, mynumber);
		am_c = count(c, size_c, mynumber);
	
		output_file = fopen(argv[4], "a");
		fprintf(output_file, "Number: %5.2lf \n", mynumber);
		fprintf(output_file, "a: %d \nb: %d \nc: %d \n", am_a, am_b, am_c);

		// finding max of counted values
		max = am_a;
		if (am_b > max) max = am_b;
		if (am_c > max) max = am_c;

		// output
		if (max == 0){
			fprintf(output_file, "В массивах нет чисел, меньше (%5.2lf)\n", mynumber);	
		}
		else{
			if (am_a == max && am_b == max && am_c == max){	
				fprintf(output_file, "Массивы А, B, C, кол-во: (%d)\n", max);
			}
			else if (am_a == max && am_b == max){	
				fprintf(output_file, "Массивы А и B, кол-во: (%d)\n", max);
			}
			else if (am_a == max && am_c == max){	
				fprintf(output_file, "Массивы A и C, кол-во: (%d)\n", max);
			}
			else if (am_b == max && am_c == max){	
				fprintf(output_file, "Массивы B и C, кол-во: (%d)\n", max);
			}
			else if (am_a == max){
				fprintf(output_file, "Массив A, кол-во: (%d)\n", max);
			}	
			else if (am_b == max){
				fprintf(output_file, "Массив B, кол-во: (%d)\n", max);
			}
			else if (am_c == max){
				fprintf(output_file, "Массив C, кол-во: (%d)\n", max);
			}

		}
		main_flag = 0;
		fclose(output_file);

	}
	else{
		main_flag = 1;
	}
	
	if (a) delete[] a;
	if (b) delete[] b;
	if (c) delete[] c;

	return main_flag;

}


