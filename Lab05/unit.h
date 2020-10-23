#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef double(*myfunc)(double);

double userfunction(double a);

double* array_input(int& arr_size, char *filename);

int count(double arr[], int arr_size, double mynumber, myfunc f);
	
int print_array(int arr_size, double arr[], char *filename, char name, myfunc f);
