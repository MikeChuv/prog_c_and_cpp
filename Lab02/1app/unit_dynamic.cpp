#include <stdio.h>
#include <stdlib.h>


// ввод массива
double** dynamic_matrix_input(int& rows, int& colls, char *filename){
	FILE *input_file;
	int flag = 0;
	double **return_value = nullptr;
	double **arr = nullptr;

	if ((input_file = fopen(filename, "r")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}

	if (!flag && (fscanf(input_file, "%d", &rows) < 1) && (fscanf(input_file, "%d", &colls) < 1) ){
		printf("Ошибка чтения из файла '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	if (!flag && ((rows <= 0) || (colls <= 0)) ){
		printf("Неверно задан размер массива. Допустимо от 1. Файл: '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	if (!flag){
		arr = new double* [rows];
		for(int i = 0; i < colls; i++){
			arr[i] = new double [colls];
		}
	}
	for (int i = 0; (i < rows) && !flag; i++){
		for(int j = 0; (j < colls) && !flag; j++){
			if (fscanf(input_file, "%lf", &arr[i][j]) < 1){
				printf("Ошибка чтения из файла '%s'\n", filename);
				fclose(input_file);
				flag = 1;
				for(int k = 0; k < colls; k++){
					delete[] arr[k];

				}
				delete [] arr;
			}
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



int print_dynamic_matrix(double** arr, int rows, int colls, char *filename, char name){
	FILE *output_file;
	int flag = 0;

	if ((output_file = fopen(filename, "a")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}
	else {
		fprintf(output_file, "%c: \n", name);
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < colls; j++){
				fprintf(output_file, "%5.2lf ", arr[i][j]);
			}
			fprintf(output_file, "\n");
		}

		fprintf(output_file, "\n");
	}
	fclose(output_file);
	return flag;
}

double dynamic_max_all(double** arr, int rows, int colls){
	double max = arr[0][0];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < colls; j++){
			if (arr[i][j] > max){
				max = arr[i][j];
			}
		}
	}
	return max;
}


static double max_in_row(double vec[], int colls){
	double max = vec[0];
		for(int i = 0; i < colls; i++){
			if(vec[i] > max){
				max = vec[i];
			}
		}
	return max;
}

double dynamic_max_rows(double** arr, int rows, int colls){
	double max = max_in_row(arr[0], colls);
	for(int i = 1; i < rows; i++){
		double current_max = max_in_row(arr[i], colls);
		if (current_max > max){
			max = current_max;
		}
	}
	return max;	
}


void dynamic_positive_count_all(double** arr, int rows, int colls, int vec[]){
	for(int i = 0; i < rows; i++){
		int counter = 0;
		for(int j = 0; j < colls; j++){
			if(arr[i][j] > 0){
				counter++;
			}
		}
		vec[i] = counter;
	}
	return;
}

static int positive_in_row(double vec[], int colls){
	int counter = 0;
	for(int i = 0; i < colls; i++){
		if(vec[i] > 0){
			counter++;
		}
	}
	return counter;
}

void dynamic_positive_count_rows(double** arr, int rows, int colls, int vec[]){
	for(int i = 0; i < rows; i++){
		vec[i] = positive_in_row(arr[i], colls);
	}
	return;
}



