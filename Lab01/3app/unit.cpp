#include <stdio.h>
#include <stdlib.h>

const int nmax = 10;

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

int count(double arr[], int arr_size, double mynumber){
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

