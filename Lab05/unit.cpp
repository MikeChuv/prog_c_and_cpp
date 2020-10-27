#include "unit.h"

double userfunction(double a){
	return (a == 0) ? 0 : log(abs(a)) + sin(2 * a) - 1;
}


// ввод массива
double* array_input(int& arr_size, char *filename){
	FILE *input_file;
	int flag = 0;
	double *return_value = nullptr;
	double *arr = nullptr;

	if ((input_file = fopen(filename, "r")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}

	if (!flag && fscanf(input_file, "%d", &arr_size) < 1){
		printf("Ошибка чтения из файла '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	if (!flag && (arr_size <= 0)){
		printf("Неверно задан размер массива. Допустимо от 1. Файл: '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	if (!flag){
		arr = new double [arr_size];
	}
	for (int i = 0; (i < arr_size) && !flag; i++){
		if (fscanf(input_file, "%lf", &arr[i]) < 1){
			printf("Ошибка чтения из файла '%s'\n", filename);
			fclose(input_file);
			flag = 1;
			delete[] arr;
		}
	}

	if(flag){
		return_value = nullptr;
	}
	else{
		return_value = arr;
	}
	fclose(input_file);
	return return_value;
}

int count(double arr[], int arr_size, double mynumber, myfunc f){
	int am = 0; //counter

	for (int i = 0; i < arr_size; i++){
		if(f(arr[i]) < mynumber){
			am++;
		}
	}

	return am;
}


int print_array(int arr_size, double arr[], char *filename, char name, myfunc f){
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
		for(int i = 0; i < arr_size; i++){
			fprintf(output_file, "(%5.2lf) ",f(arr[i]));
		}


		fprintf(output_file, "\n\n");
	}
	fclose(output_file);
	return flag;
}


