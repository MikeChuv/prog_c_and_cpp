#include <stdio.h>


// ввод динамической матрицы из файла
double** dynamic_matrix_input(int& rows, int& colls, char *filename){
	FILE *input_file; // входной файл
	int flag = 0; // флаг ошибки
	double **return_value = nullptr; // возвращаемое значение
	double **arr = nullptr; // указатель для матрицы

	// проверка открывается ли файл
	if ((input_file = fopen(filename, "r")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}
	// проверка на ошибку чтения
	else if ( fscanf(input_file, "%d", &rows) < 1 || fscanf(input_file, "%d", &colls) < 1){
		printf("Ошибка чтения из файла '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	// аномалия - неверные данные
	else if ( (rows <= 0) || (colls <= 0) ){
		printf("Неверно задан размер массива. Допустимо от 1. Файл: '%s'\n", filename);
		fclose(input_file);
		flag = 1;
	}

	else{

		// выделяем память
		arr = new double* [rows];
		for(int i = 0; i < rows; i++){
			arr[i] = new double [colls];
		}
	
		// вводим
		for (int i = 0; (i < rows) && !flag; i++){
			for(int j = 0; (j < colls) && !flag; j++){
				// проверка ошибки ввода
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

	}
	// обработка флага ошибки
	if(flag){
		return_value = nullptr;
	}
	else{
		return_value = arr;
	}
	fclose(input_file);
	return return_value;
}


// вывод динамической матрицы
int print_dynamic_matrix(double** arr, int rows, int colls, char *filename){
	FILE *output_file; // вызодной файл
	int flag = 0; // флаг ошибки вывода

	// пытаемся открыть файл
	if ((output_file = fopen(filename, "w")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		flag = 1;
	}
	else {
		// выводим матрицу
		fprintf(output_file, "Matrix : \n");
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


int has_positive(double* arr, int colls){
	int idx = -1;
	// поиск первого положительного
	for (int i = 0; i < colls && idx == -1; i++) 
		if (arr[i] > 0) {
			idx = i;
		}
	return idx;
}


// ищем минимальный положительный в строке
double min_positive(double* arr, int colls){
	double min = -1; // начальное значение

	int first_positive = has_positive(arr, colls);
	if (first_positive != -1){
		min = arr[first_positive];
		// поиск минимального
		for (int i = first_positive; i < colls; i++){
			if ( (arr[i] < min) && (arr[i] > 0)) min = arr[i];
		}
	}
	return min;
}

// посик максимального из минимальных
double max_of_mins(double** arr, int rows, int colls){
	double max = min_positive(arr[0], colls); // начальное значение
	// ищем максимум
	for (int i = 1; i < rows; i++){
		double cur = min_positive(arr[i], colls);
		max = cur > max ? cur : max;
	}
	return max;
}

// вывод результата
void print_result(double res, char* filename){
	FILE* output_file; // выходной файл
	if ((output_file = fopen(filename, "a")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
	}
	else {
		fprintf(output_file, "Result = %lf\n", res);
	}
	fclose(output_file);
}


int main(int argc, char* argv[]){
	
	int flag = 0;
	int rows, colls;

	// проверка количества параметров
	if (argc < 3) {
		printf("Недостаточно параметров!\n");
		flag = 1;
	}
	else{
		// пытаемся ввести матрицу
		double** arr = dynamic_matrix_input(rows, colls, argv[1]);
		// если не получилось
		if (!arr) flag = 1;
		else{
			// ищем результат, если он -1, то выводим сообщение
			double result = max_of_mins(arr, rows, colls);
			if (result < 0){
				printf("Нет строк с положительными элементами\n");
			}
			// выводим матрицу
			print_dynamic_matrix(arr, rows, colls, argv[2]);
			// выводим ответ
			print_result(result, argv[2]);
		}
	}

	return flag;
}
