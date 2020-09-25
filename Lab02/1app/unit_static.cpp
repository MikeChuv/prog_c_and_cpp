#include <stdio.h>
#include <stdlib.h>

const int nmax = 10;


// static matrix input
int input(double arr[][nmax], int& rows, int& colls, char* filename){

	FILE* input_file;
	int flag = 0;

	if ((input_file = fopen(filename, "r")) == NULL){
		flag = 1;
		printf("Невозможно открыть файл '%s'\n", filename);
	}
	else if (fscanf(input_file, "%d", &rows) < 1 || fscanf(input_file, "%d", &colls) < 1){
		flag = 1;
		printf("Неверный формат\n");
		fclose(input_file);
	}
	else if(rows <= 0 || rows > nmax || colls <= 0 || colls > nmax ){
		flag = 1;
		printf("Неверно задан размер массива\n");
		fclose(input_file);
	}
	else{
		for(int i = 0; (i < rows) && !flag; i++){
			for(int j = 0; (j < colls) && !flag; j++){
				if(fscanf(input_file, "%lf", &arr[i][j]) < 1){
					printf("Неверный формат!\n");
					flag = 1;
				}
			}
		}
		fclose(input_file);
	}
	

	return flag;

}


void print_static_matrix(double arr[][nmax], int rows, int colls, char* filename, char matrix_name){
	FILE* output_file;
	output_file = fopen(filename, "a");
	fprintf(output_file, "Matrix %c: \n", matrix_name);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < colls; j++){
			fprintf(output_file, " %5.2lf", arr[i][j]);
		}
		fprintf(output_file, "\n");
	}
	fprintf(output_file, "\n");
	fclose(output_file);
	return;
}

// prints 1d array (used for both static and dynamic implementation)
void print_vector(int vec[], int length, char* filename){
	FILE* output_file;
	output_file = fopen(filename, "a");
	fprintf(output_file, "Vector: \n");
	for(int i = 0; i < length; i++){
		fprintf(output_file, " %4d", vec[i]);
	}
	fprintf(output_file, "\n");
	fclose(output_file);
	return;
}


// prints float point number with a message to a file (useb for both static and dynamic implementation) 
void message_with_double(double number,const char* message, char* filename){
	FILE* output_file;
	output_file = fopen(filename, "a");
	fprintf(output_file, "%s %5.2lf\n", message, number);
	fclose(output_file);
}




// ----- Finding max value -----
//

double static_max_all(double arr[][nmax], int rows, int colls){
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

double static_max_rows(double arr[][nmax], int rows, int colls){
	double max = max_in_row(arr[0], colls);
	for(int i = 1; i < rows; i++){
		double current_max = max_in_row(arr[i], colls);
		if (current_max > max){
			max = current_max;
		}
	}
	return max;	
}



// ----- Counting positives
//



void static_positive_count_all(double arr[][nmax], int rows, int colls, int vec[]){
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

void static_positive_count_rows(double arr[][nmax], int rows, int colls, char* filename){
	FILE* output_file;
	output_file = fopen(filename, "a");
	fprintf(output_file, "\n");
	for(int i = 0; i < rows; i++){
		int counted = positive_in_row(arr[i], colls);
		fprintf(output_file, "Positives in row %d : %2d\n", i, counted); 
	}
	fclose(output_file);
	return;
}



