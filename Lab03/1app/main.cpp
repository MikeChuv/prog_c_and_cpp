/*
 *
 * Вариант 3: Каждая запись представляет собой 2 числа типа long int. 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "unit.h"
#include "utils.h"


int main(int argc, char* argv[]){
	int flag = 0;
	char* textfile_name;
	char* binfile_name;
	char* outfile_name;
	char* logfile_name;
	int first, second;

	// checking amount of arguments 
	if (argc < 5){
		flag = 1;
		printf("Not enough params\n");
	}
	else{
		textfile_name = argv[1];
		binfile_name = argv[2];
		outfile_name = argv[3];
		logfile_name = argv[4];
	}
	
	// reading data from text to binary file
	if(!flag && text_to_bin(textfile_name, binfile_name)){
		log_message(logfile_name, "Error reading from text to binary");
		flag = 1;
	}
	else if(!flag){
		log_message(logfile_name, "Binary created");
	}


	// writing data from binary to output file before swapping
	if(!flag && bin_to_text(binfile_name, outfile_name)){
		log_message(logfile_name, "Error reading from binary to text");
		flag = 1;
	}
	else if (!flag){
		log_message(logfile_name, "Data from binary written to out.txt");
	}

	// entering records numbers to swap
	if (!flag){	
		printf("To swap:\n");
		scanf("%d %d", &first, &second);
		log_message(logfile_name, "Selected records:");
		log_int(logfile_name, first);
		log_int(logfile_name, second);
	}

	// swapping records
	if(!flag && swap_numbers(binfile_name, first, second, logfile_name)){
		flag = 1;
	}
	else if(!flag){
		log_message(logfile_name, "Swapped");
	}

	// writing data from binary to output file after swapping
	if(!flag && bin_to_text(binfile_name, outfile_name)){
		flag = 1;
	}
	else if(!flag){
		log_message(logfile_name, "Binary with swapped written to out.txt");
	}
	log_message(logfile_name, "Exitting..");

	return flag;
}

