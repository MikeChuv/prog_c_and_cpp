/*
	Вариант 3: Даны две матрицы разного размера. Для той из матриц, в которой больше максимальный элемент, найти количество положительных элементов в каждой строке.
*/

#include <stdio.h>
#include <stdlib.h>

const int nmax = 10;



int input(double arr[][nmax], int* rows, int* colls);

double max(double arr[][nmax], int rows, int colls);

int count_positive(double arr[][nmax],int rows, int colls, int vec[]); // вывод в подпрограмму или нужно в мэйн обязательно выводить??



int main(int argc, char* argv[]){
	double a[nmax][nmax], b[nmax][nmax];
	int rows_a, colls_a, rows_b, colls_b;
	int pos_a[nmax], pos_b[nmax];
	int flag = 0;

	if (input(a, &rows_a, &colls_b) && input(b, &rows_b, &colls_b)){
		double max_a = max(a, rows_a, colls_a);
		double max_b = max(b, rows_b, colls_b);

		if (max_a > max_b) {
			count_positive(a, rows_a, colls_a, pos_a);
			count_positive(b, rows_b, colls_b, pos_b);
		}


	}
	
	
	return 0;		
}



int input(double arr[][nmax], int* rows, int* colls){

	int flag = 0;

	printf("Количество строк и столбцов матрицы: \n");
	if (scanf("%d", rows) < 1 || scanf("%d", colls) < 1){
		flag = 1;
		printf("Неверный формат\n");
	}
	else if(*rows <= 0 || *rows > nmax || *colls <= 0 || *colls > nmax ){
		flag = 1;
		printf("Неверно задан размер массива\n");
	}
	else{
		for(int i = 0; (i < *rows) && !flag; i++){
			for(int j = 0; (i < *colls) && !flag; i++){
				printf("a[%d][%d] = ", i, j);
				if(scanf("%lf", &arr[i][j]) < 1){
					printf("Неверный формат!\n");
					flag = 1;
				}
			}
		}
	}

	return flag;


}
