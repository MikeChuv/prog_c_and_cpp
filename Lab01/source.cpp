/*
	Вариант 25
	Определить в каком массиве больше минимум элементов, больших заданного числа. Если в двух или трёх массивах минимумы совпадают, вывести соответствующее сообщение. 
*/


#include <cstdio>

// #include <stdio.h>
// #include <stdlib.h>

const int nmax = 10;

// ввод массива
int array_input(int *arr_size, double x[], char *filename);

// поиск минимумов, больших заданного числа
double find_min(double x[], int size, double mynumber);




int main(int argc, char *argv[]){
	// массивы, минимумы в массивах, общий максимум и количества эл-тов в массивах
	double a[nmax], b[nmax], c[nmax];
	double min_a, min_b, min_c, max, mynumber;
	int size_a, size_b, size_c;

	if(argc < 4){
		printf("Недостаточно параметров\n");
		return 1;
	}
	if (!array_input(&size_a, a, argv[1])) return 1;
	if (!array_input(&size_b, b, argv[2])) return 1;
	if (!array_input(&size_c, c, argv[3])) return 1;

	printf("Введите число: ");
	if (scanf("%lf", &mynumber) < 1){
		printf("Неверный формат");
		return 1;
	}


	min_a = find_min(a, size_a, mynumber);
	min_b = find_min(b, size_b, mynumber);
	min_c = find_min(c, size_c, mynumber);

	// printf("mina = %lf \nminb = %lf \nminc = %lf\n", min_a, min_b, min_c);

	max = min_a;
	if (min_b > max) max = min_b;
	if (min_c > max) max = min_c;


	if (max == mynumber){
		printf("В массивах нет чисел, больше (%9.3lf)\n", mynumber);
	}
	else{
		if (min_a == max){
			printf("Массив А имеет максимальное (%9.3lf) из минимумов, больших заданного числа\n", max);
		}

		if (min_b == max){
			printf("Массив B имеет максимальное (%9.3lf) из минимумов, больших заданного числа\n", max);
		}
	
		if (min_c == max){
			printf("Массив C имеет максимальное (%9.3lf) из минимумов, больших заданного числа\n", max);
		}
	}


	return 0;
}






// ввод массива
int array_input(int *arr_size, double arr[], char *filename){
	FILE *input_file;

	if ((input_file = fopen(filename, "r")) == NULL){
		printf("Невозможно открыть файл '%s'\n", filename);
		return 0;
	}

	if (fscanf(input_file, "%d", arr_size) < 1){
		printf("Ошибка чтения из файла '%s'\n", filename);
		fclose(input_file);
		return 0;
	}

	if (*arr_size < 0 || *arr_size > nmax){
		printf("Неверно задан размер массива. Допустимо от 1 до %d. Файл: '%s'\n", nmax, filename);
		fclose(input_file);
		return 0;
	}

	for (int i = 0; i < *arr_size; i++){
		if (fscanf(input_file, "%lf", &arr[i]) < 1){
			printf("Ошибка чтения из файла '%s'\n", filename);
			fclose(input_file);
			return 0;
		}
	}

	fclose(input_file);
	return 1;
}

// подсчет минимумов, больших заданного числа
double find_min(double arr[], int arr_size, double mynumber){

	double min;
	
	int flag = 0;
	for (int i = 0; i < arr_size; i++){
		if ((arr[i] > mynumber) && (!flag) ){
			min = arr[i];
			flag = 1;
		}
		if (flag && (arr[i] < min) && (arr[i] > mynumber)) min = arr[i];
	}

	if (flag){
		return min;
	}
	else{
		return mynumber;
	}

}
