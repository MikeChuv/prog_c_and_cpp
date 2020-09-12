/*
	Определить в каком массиве больше количество элементов, меньших заданного числа. Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение. 
*/


#include <stdio.h>
#include <stdlib.h>


const int nmax = 10;


// ввод массива
int array_input(int& arr_size, double arr[], char *filename);
// количество элементов, меньших заданного числа
int count(double arr[],int arr_size, double mynumber);
 
int print_array(int arr_size, double arr[], char *filename, char name);


int main(int argc, char *argv[]){
	double a[nmax], b[nmax], c[nmax];
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


	// array entry and checking if values are valid
	if (!main_flag && !array_input(size_a, a, argv[1]) && !array_input(size_b, b, argv[2]) && !array_input(size_c, c, argv[3])){


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
		fclose(output_file);
		main_flag = 0;
	}
	else{
		main_flag = 1;
	}

	return main_flag;

}


// ввод массива
int array_input(int& arr_size, double arr[], char *filename){
	FILE *input_file;
	int flag = 0;

	if ((input_file = fopen(filename, "r")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}

	if (!flag && fscanf(input_file, "%d", &arr_size) < 1){
		printf("Ошибка чтения из файла '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	if (!flag && (arr_size < 0 || arr_size > nmax)){
		printf("Неверно задан размер массива. Допустимо от 1 до %d. Файл: '%s'\n", nmax, filename);
		fclose(input_file);
		flag = 1;
	}

	for (int i = 0; (i < arr_size) && !flag; i++){
		if (fscanf(input_file, "%lf", &arr[i]) < 1){
			printf("Ошибка чтения из файла '%s'\n", filename);
			fclose(input_file);
			flag = 1;
		}
	}

	fclose(input_file);
	return flag;
}

int count(double arr[],int arr_size, double mynumber){
	int am = 0; //counter

	for (int i = 0; i < arr_size; i++){
		if(arr[i] < mynumber){
			am++;
		}
	}

	return am;
}




int print_array(int arr_size, double arr[], char *filename, char name){
	FILE *output_file;
	int flag = 0;

	if ((output_file = fopen(filename, "a")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}
	else {
		fprintf(output_file, "%c: \n", name);
		for(int i = 0; i < arr_size; i++){
			fprintf(output_file, "%5.2lf ", arr[i]);
		}

		fprintf(output_file, "\n");
	}
	fclose(output_file);
	return flag;
}
