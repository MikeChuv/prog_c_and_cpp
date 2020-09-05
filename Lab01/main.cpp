#include <stdio.h>
#include <stdlib.h>


const int nmax = 10;


// ввод массива
int array_input(int *arr_size, double arr[]);
// поиск минимумов, больших заданного числа
int count(double arr[], int arr_ize, double mynumber);
 



int main(int argc, char *argv[]){
	double a[nmax], b[nmax], c[nmax];
	int am_a, am_b, am_c, max;
	double mynumber;
	int size_a, size_b, size_c;
	int main_flag = 0;

	printf("Введите число: ");
	if (scanf("%lf", &mynumber) < 1){
		printf("Неверный формат\n");
		main_flag = 1;
	}



	if (!main_flag && array_input(&size_a, a) && array_input(&size_b, b) && array_input(&size_c, c)){

		am_a = count(a, size_a, mynumber);
		am_b = count(b, size_b, mynumber);
		am_c = count(c, size_c, mynumber);
	
		printf("a: %d \nb: %d \nc: %d \n", am_a, am_b, am_c);

		max = am_a;
		if (am_b > max) max = am_b;
		if (am_c > max) max = am_c;

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

	return main_flag;

}



int array_input(int *arr_size, double arr[]){

	int flag;
	printf("Введите размер массива: ");
	if (scanf("%d", arr_size) < 1){
		flag = 0;
		printf("Неверный формат\n");
	}	
	else{
		if (*arr_size < 0 || *arr_size > nmax){
			printf("Неверно задан размер массива. Допустимо от 1 до %d\n", nmax);
			flag = 0;
		}
		else{
			int loop_flag = 0;
			//  не структурно наверное
			for (int i = 0; (i < *arr_size) && (!loop_flag); i++){
				if(scanf("%lf", &arr[i]) < 1){
					loop_flag = 1;
					printf("Неверный формат\n");
				}
			}
			flag = !loop_flag;
		}
	}
	return flag;
}



int count(double arr[], int arr_size, double mynumber){
	int am = 0;

	for (int i = 0; i < arr_size; i++){
		if(arr[i] < mynumber){
			am++;
		}
	}


	return am;
}
