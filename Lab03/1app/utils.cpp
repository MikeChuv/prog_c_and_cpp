#include <stdio.h>
#include <stdlib.h>


// printing message to a log file
void log_message(char* log, const char* message){
	FILE* log_file; 
	log_file = fopen(log, "a");
	fprintf(log_file, "%s\n", message);
	fclose(log_file);
}


// printing int number to a log file
void log_int(char* log, int number){
	FILE* log_file; 
	log_file = fopen(log, "a");
	fprintf(log_file, "%d\n", number);
	fclose(log_file);
}


