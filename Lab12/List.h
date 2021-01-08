#pragma once

#include <iostream>
#include "Exceptions.h"

template <class T>
class Node {
	public:
		Node(const T& t, Node* n) : value(t), next(n) {}
		Node<T> * next_node() { return this->next; }
		const T get_value() const { return value; }
		T value;
		Node* next;
};


template <class T>
class List {
	public:
		List();
		List(const List<T>& val);
		~List();

		int length() const;
		bool is_empty() const;

		Node<T>* get_first() const {return first;}
		Node<T>* get_last() const {return last;}

		void push_front(const T& value);
		void push_back(const T& value);
		void push_after(int index, const T& value);

		void delete_front();
		void delete_back();
		void delete_current(int index);

		T pop_front();
		T pop_back();
		T pop_current(int index);

		Node<T> * get_node(int index) const;
		
		T & operator [] (int index);
		const T & operator [] (int index) const;

		bool operator == (const List& list) const;
		List<T> & operator = (const List& list);

	private:
		Node<T> *first, *last;
};


template <class T>
std::ostream& operator<< (std::ostream& f, const List<T>& arg_list);

template <class T> 
std::istream& operator>> (std::istream& f, List<T>& arg_list);



template <class T>
void read_list(std::istream& in, List<T>& arg_list);

template <class T>
void print_list(std::ostream& out, const List<T>& arg_list, const char* msg);



#include "List.ipp"

