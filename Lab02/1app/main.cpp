/*
	Вариант 3: Даны две матрицы разного размера. Для той из матриц, в которой больше максимальный элемент, найти количество положительных элементов в каждой строке.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_dynamic.h"

#include "unit_static.h"


int main(int argc, char* argv[]){
	double a[nmax][nmax], b[nmax][nmax];
	int rows_a, colls_a, rows_b, colls_b;
	int counted_vec[nmax];
	int flag = 0;

	// проверка на количество аргументов командной строки
	if (argc < 5){
		flag = 1;
		printf("Недостаточно параметров\n");
	}
	// установка нужного ключа
	// s - static array
	// d - dynamic array
	// a - full matrix
	// r - by rows
	int sa = strcmp(argv[4], "-sa") == 0;
	int sr = strcmp(argv[4], "-sr") == 0;
	int da = strcmp(argv[4], "-da") == 0;
	int dr = strcmp(argv[4], "-dr") == 0;



	if( (sa || sr) && !flag ){
		// статический массив
		if (input(a, rows_a, colls_a, argv[1]) || input(b, rows_b, colls_b, argv[2])){
			flag = 1;
		}
		else if(sa){
			//static all
			print_static_matrix(a, rows_a, colls_a, argv[3], 'A');
			print_static_matrix(b, rows_b, colls_b, argv[3], 'B');

			double max_a = static_max_all(a, rows_a, colls_a);
			double max_b = static_max_all(b, rows_b, colls_b);
			printf("Max_a = %lf\n", max_a);
			printf("Max_b = %lf\n", max_b);
			if (max_a > max_b){
				//	кол-во положительных в каждой строке в А
				static_positive_count_all(a, rows_a, colls_a, counted_vec);
				print_vector(counted_vec, rows_a, argv[3]);
			}
			else{
				//	кол-во положительных в каждой строке в Б
				static_positive_count_all(b, rows_b, colls_b, counted_vec);
				print_vector(counted_vec, rows_b, argv[3]);
			}
		}
		else{
			//static rows
			print_static_matrix(a, rows_a, colls_a, argv[3], 'A');
			print_static_matrix(b, rows_b, colls_b, argv[3], 'B');

			double max_a = static_max_rows(a, rows_a, colls_a);
			double max_b = static_max_rows(b, rows_b, colls_b);
			printf("Max_a = %lf\n", max_a);
			printf("Max_b = %lf\n", max_b);

			if (max_a > max_b){
				//	кол-во положительных в каждой строке в А
				static_positive_count_rows(a, rows_a, colls_a, counted_vec);
				print_vector(counted_vec, rows_a, argv[3]);
			}
			else{
				//	кол-во положительных в каждой строке в Б
				static_positive_count_rows(b, rows_b, colls_b, counted_vec);
				print_vector(counted_vec, rows_b, argv[3]);
			}

		}
			
	}
	else if( (da || dr) && !flag ){
		// динамический массив
		// input
		double** matrix_a = dynamic_matrix_input(rows_a, colls_a, argv[1]);
		double** matrix_b = dynamic_matrix_input(rows_b, colls_b, argv[2]);
		
		if(!matrix_a || !matrix_b){
			flag = 1;
		}
		else if(da){
			// full
			print_dynamic_matrix(matrix_a, rows_a, colls_a, argv[3], 'A');
			print_dynamic_matrix(matrix_b, rows_b, colls_b, argv[3], 'B');

			double max_a = dynamic_max_all(matrix_a, rows_a, colls_a);
			double max_b = dynamic_max_all(matrix_b, rows_b, colls_b);
			if(max_a > max_b){
				dynamic_positive_count_all(matrix_a, rows_a, colls_a, counted_vec);
				print_vector(counted_vec, rows_a, argv[3]);
			}
			else{
				dynamic_positive_count_all(matrix_b, rows_b, colls_b, counted_vec);
				print_vector(counted_vec, rows_b, argv[3]);
			}
		}
		else{

			print_dynamic_matrix(matrix_a, rows_a, colls_a, argv[3], 'A');
			print_dynamic_matrix(matrix_b, rows_b, colls_b, argv[3], 'B');
			double max_a = dynamic_max_rows(matrix_a, rows_a, colls_a);
			double max_b = dynamic_max_rows(matrix_b, rows_b, colls_b);
			// rows
			if(max_a > max_b){
				dynamic_positive_count_rows(matrix_a, rows_a, colls_a, counted_vec);
				print_vector(counted_vec, rows_a, argv[3]);
			}
			else{
				dynamic_positive_count_rows(matrix_a, rows_a, colls_a, counted_vec);
				print_vector(counted_vec, rows_a, argv[3]);
	
			}
		}
		printf("Dynamic\n");
	}
	else{
		printf("Wrong key\n");
		flag = 1;
	}



	return flag;
}



