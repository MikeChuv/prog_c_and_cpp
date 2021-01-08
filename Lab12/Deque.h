#pragma once

#include <iostream>
#include "Exceptions.h"

template <class T>
class Deque{
	public:
		Deque();
		Deque(const Deque<T>& r_deque);
		~Deque();

		bool is_empty() const;

		void push_front(const T& value);
		void push_back(const T& value);

		T& pop_front();
		T& pop_back();

		void print_data() const;

	private:
		void resize(int new_size);
		int size, count, first, last;
		T* data;
		const int block_size = 5;
};

template <class T>
std::ostream& operator<< (std::ostream& f, Deque<T>& arg_deque);

template <class T> 
std::istream& operator>> (std::istream& f, Deque<T>& arg_deque);



template <class T>
void read_deque(std::istream& in, Deque<T>& arg_deque);

template <class T>
void print_deque(std::ostream& out, Deque<T>& arg_deque, const char* msg);

#include "Deque.ipp"