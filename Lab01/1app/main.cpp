#include <stdio.h>
#include <stdlib.h>


const int nmax = 10;


// ввод массива
int array_input(int *arr_size, double arr[]);
// количество элементов, меньших заданного числа
int count(double arr[], int arr_ize, double mynumber);
 



int main(int argc, char *argv[]){
	double a[nmax], b[nmax], c[nmax];
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


	// array entry and checking if values are valid
	if (!main_flag && !array_input(&size_a, a) && !array_input(&size_b, b) && !array_input(&size_c, c)){

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

	return main_flag;

}



int array_input(int *arr_size, double arr[]){

	int flag = 0; // err flag

	// array size entry
	printf("Введите размер массива: ");
	if (scanf("%d", arr_size) < 1){
		flag = 1;
		printf("Неверный формат\n");
	}	
	else{
		if (*arr_size < 0 || *arr_size > nmax){
			printf("Неверно задан размер массива. Допустимо от 1 до %d\n", nmax);
			flag = 1;
		}
		else{
			//  не структурно наверное, но легко переписать на 
			//  int i = 0;
			//  while((i < *arr_size) && !flag){
			//  	//impl
			//  	i++;
			//  }
			for (int i = 0; (i < *arr_size) && !flag; i++){
				if(scanf("%lf", &arr[i]) < 1){
					flag = 1;
					printf("Неверный формат\n");
				}
			}
		}
	}
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




