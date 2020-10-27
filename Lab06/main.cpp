#include <stdio.h>

int main(int argc, char* argv[]){
	const unsigned char size = sizeof(unsigned int) * 8;
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
	if ( n > size || n < 0 || p > size || p < 0 || p < n){
		flag = 1;
		fprintf(logfile, "Invalid N or P \n N = %d \n P = %d\n", n, p);
	}
	else{
		unsigned int mask = 1;
		fprintf(logfile, "After : \tX = %08x\n", x | ((mask << n) - 1) << (32 - p));

	}
	return flag;
}
