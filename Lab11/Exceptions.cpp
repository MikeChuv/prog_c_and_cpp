#include "Exceptions.h"
#include <stdio.h>

StringException::StringException(){}

void StringException::print_error() const{
	printf("StringException Error: %s\n", message);
}

void IndexOutOfRange::print_error() const{
	printf("IndexOutOfRange Error in: %s \tIndex: %d\n", details, idx);
}

void BadAlloc::print_error() const{
	printf("BadAlloc Error in: %s \tSize: %d\n", details, inv_size);
}
