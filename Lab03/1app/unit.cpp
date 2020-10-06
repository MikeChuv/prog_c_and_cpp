#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

// define record type
typedef long int Record[2];
size_t rec_size = 2 * sizeof(long int);



// parse record from a line in input file 
int text_to_bin(char* textfile, char* binfile){
	FILE* input_file;
	FILE* output_file;
	int flag = 0;
	Record rec;

	
	if ((input_file = fopen(textfile, "r")) == NULL){
		flag = 1;
	}
	if (!flag && (output_file = fopen(binfile, "wb")) == NULL){
		flag = 1;
	}


//	int scanned = fscanf(input_file, "%ld%*[ ]", &rec[0], &rec[1]);
//	while(scanned != EOF){
//		if(scanned > 1){
//			printf("%4ld \t %4ld\n",rec[0], rec[1] );
//			fwrite(rec, 2 * sizeof(long int), 1, output_file);
//		}
//		scanned = fscanf(input_file, "%ld%*[^\n]", &rec[0], &rec[1]);
//	}

	int counter;
	while (!flag && !feof(input_file)){
		if(fscanf(input_file, "%ld%*[ ]", &rec[0]) == 1) {
			char n;
			fscanf(input_file, "%c", &n);
			if(n != '\n' && n != '.'){
				fseek(input_file, -1, SEEK_CUR);
				double d;
				if(fscanf(input_file, "%lf%*[ ]", &d) == 1){
					double tmp;
					if (!modf(d, &tmp)){
						rec[1] = (long int)d;
						fwrite(rec, rec_size,  1, output_file);
					}
				}
			}
			else {
				fseek(input_file, -1, SEEK_CUR);
			}
			counter++;
		}
		fscanf(input_file, "%*[^\n]\n");
	}

	//printf("Counter = %d\n",counter);
	if (!counter){
		flag = 1;
	}
	if (!flag){
		fclose(input_file);
		fclose(output_file);
	}

	return flag;
}






// writing data from binary to taxt file
int bin_to_text(char* binfile, char* textfile){
	FILE* input_file;
	FILE* output_file;
	int flag = 0;
	Record rec;
	
	if ((input_file = fopen(binfile, "rb")) == NULL){
		flag = 1;
	}
	else if ((output_file = fopen(textfile, "a")) == NULL){
		flag = 1;
	}
	else{

		// counting amount of records in bunary	
		fseek(input_file, 0, SEEK_END);
		int n = ftell(input_file) / (rec_size);
		if (n == 0){
			flag = 1;
		}
		else{
			fseek(input_file, 0, SEEK_SET);
			for(int i = 0; i < n; i++){
				fread(rec, rec_size, 1, input_file);
				fprintf(output_file, "%d: | %4ld | %4ld |\n", i, rec[0], rec[1]);
			}
		}
		fprintf(output_file, "\n\n");
		fclose(input_file);
		fclose(output_file);
	}
	return flag;
}

// logging records when swapping
static void log_bin_records(FILE* file, FILE* log_file, int n, int first, int second){
	Record rec;
	fseek(file, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		fread(rec, rec_size, 1, file);
		if (i == first || i == second){
			fprintf(log_file, "__________________\n");
			fprintf(log_file, "%c: | %4ld | %4ld |\n", '>', rec[0], rec[1]);
			fprintf(log_file, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
		}
		else{
			fprintf(log_file, "%c: | %4ld | %4ld |\n", ' ', rec[0], rec[1]);
		}
	}
	fprintf(log_file, "\n\n");
}


// function for swapping records
int swap_numbers(char* binfile, int first, int second, char* log){
	FILE* file;
	FILE* log_file;
	int flag = 0;
	Record first_rec;
	Record second_rec;
	Record rec;

	log_file = fopen(log, "a");
	if((file = fopen(binfile, "rb+")) == NULL){
		flag = 1;
	}
	else{
		fseek(file, 0, SEEK_END);
		int n = ftell(file) / (rec_size);
		fprintf(log_file, "Records in binary: %d\n", n);
		
		if(n < first || n < second){
			flag = 1;
		}
		else{
			// finding records
			fseek(file, first * rec_size, SEEK_SET);
			fread(first_rec, rec_size, 1, file);
			fprintf(log_file, "first(%d) = %4ld %4ld\n", first, first_rec[0], first_rec[1]);

			fseek(file, second * rec_size, SEEK_SET);
			fread(second_rec, rec_size, 1, file);
			fprintf(log_file, "second(%d) = %4ld %4ld\n",second, second_rec[0], second_rec[1]);
			
			// logging before
			fprintf(log_file, "\nBefore swapping:\n");
			log_bin_records(file, log_file, n, first, second);

			// swapping
			fseek(file, first * rec_size, SEEK_SET);
			fwrite(second_rec, rec_size,  1, file);
			fseek(file, second * rec_size, SEEK_SET);
			fwrite(first_rec, rec_size,  1, file);
			
			// logging after
			fprintf(log_file, "\nAfter swapping:\n");
			log_bin_records(file, log_file, n, first, second);

		}

	}
	if (!flag){	
		fclose(file);
		fclose(log_file);
	}
	return flag;
}
