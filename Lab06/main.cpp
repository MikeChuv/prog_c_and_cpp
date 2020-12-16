// Написать функцию, которая в числе x устанавливает 1 в n бит, находящихся слева от позиции p, остальные биты остаются без изменения. 

#include <stdio.h>


const unsigned char size = sizeof(unsigned int) * 8;


int check_input(int n, int p){
	return n >= size || n < 0 || p >= size || p < 0 || p < n;
}

unsigned int apply_mask(unsigned int x, int n, int p){
	unsigned int mask = 1;
	return x | ((mask << n) - 1) << p;
}

int main(int argc, char* argv[]){
	FILE* logfile = fopen(argv[1], "w");
	unsigned int x;
	int n, p;
	int flag = 0;

	printf("X = ");
	scanf("%d", &x);
	printf("N = ");
	scanf("%d", &n);
	printf("P = ");
	scanf("%d", &p);
	
	fprintf(logfile, "Before : \tX = %08x\n", x);
	if (check_input(n, p)){
		flag = 1;
		fprintf(logfile, "Invalid N or P \n N = %d \n P = %d\n", n, p);
	}
	else{
		x = apply_mask(x, n, p);
		fprintf(logfile, "After : \tX = %08x\n", x);
	}
	return flag;
}
