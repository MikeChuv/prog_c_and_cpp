#include "Exceptions.h"

ListException::ListException(){}

void ListException::print_error() const {
	printf("ListException error: %s\n", message);
}

void EmptyList::print_error() const {
	printf("List is empty. Details: %s\n", details);
}

void IndexOutOfRange::print_error() const {
	printf("IndexOutOfRange. Error in: %s\tIndex: %d\n", details, idx);
}


DequeException::DequeException(){}

void DequeException::print_error() const{
	printf("DequeException error: %s\n", message);
}

void EmptyDeque::print_error() const {
	printf("Deque is empty. Error in: %s\n", details);
}