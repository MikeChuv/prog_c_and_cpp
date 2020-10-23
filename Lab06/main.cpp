#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

int main(int argc, char* argv[]){
	unsigned int x = 0xFF;
	int n, p;
	printf("N = ");
	scanf("%d", &n);
	printf("P = ");
	scanf("%d", &p);
	
	const unsigned char size = sizeof(unsigned int) * 8;	
	printf("\n%08x\n", x); 
	std::cout << std::bitset<size>(x) << std::endl;
	if ( n > size || n < 0 || p > size || p < 0 || p < n){
		exit(1);
	}
	else{
		unsigned int mask = 1;
		std::cout << std::bitset<size>(x | ((mask << n) - 1) << (32 - p)) << std::endl;
		printf("%08x\n", x | ((mask << n) - 1) << (32 - p));	
		return 0;
	}
}
