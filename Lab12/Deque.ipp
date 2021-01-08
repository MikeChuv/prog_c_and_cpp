#include "Deque.h"

template <class T>
Deque<T>::Deque(){
	size = block_size;
	data = new T [size];
	count = 0;
	first = 0;
	last = 0;
}

template <class T>
Deque<T>::Deque(const Deque<T>& r_deque){
	data = new T [r_deque.size];
	first = r_deque.first;
	last = r_deque.last;
	size = r_deque.size;
	count = r_deque.count;
	if (first < last) {
		for (int i = first; i < last; i++) data[i] = r_deque.data[i];
	}
	else{
		for (int i = first; i < size; i++) data[i] = r_deque.data[i];
		for (int i = 0; i < last; i++) data[i] = r_deque.data[i];
	}
}

template <class T>
Deque<T>::~Deque(){
	delete [] data;
}

template <class T>
bool Deque<T>::is_empty() const{
	return count == 0;
}

template <class T>
void Deque<T>::push_front(const T& value){
	if (count == size){
		int blocks_to_add = first % block_size + 1;
		resize(size + blocks_to_add * block_size);
		if (first != 0){
			for (int i = 0; i < first; i++) data[i + size] = data[i];
		}
		last += size;
		size += (blocks_to_add * block_size);
	}
	if (first != 0) first--;
	else{
		for (int i = last; i > 0; i--) data[i] = data[i - 1];
		last++;
	}
	data[first] = value;
	if (last == size) last = 0;
	count++;
}


template <class T> 
void Deque<T>::push_back(const T& value){
	if (count == size){
		int blocks_to_add = first % block_size + 1;
		resize(size + blocks_to_add * block_size);
		for (int i = 0; i < first; i++) data[i + size] = data[i];
		last += size;
		size += (blocks_to_add * block_size);
	}
	data[last] = value;
	last++;
	if (last == size) last = 0;
	count++;
}

template <class T>
T& Deque<T>::pop_front(){
	if (count == 0) throw EmptyDeque("pop_front()");
	else{
		T& result = data[first];
		count--;
		first++;
		if (first == size) first = 0;
		return result;
	}
}

template <class T>
T& Deque<T>::pop_back(){
	if (count == 0) throw EmptyDeque("pop_back()");
	else{
		if (last == 0) last = size;
		T& result = data[last - 1];
		count--;
		last--;
		return result;
	}
}

template <class T>
void Deque<T>::resize(int new_size){
	T* new_data = new T [new_size];
	if (first < last){
		for (int i = first; i < last; i++) {
			new_data[i] = data[i];
			std::cout << data[i];
		}
		std::cout << '\n';
	}
	else{
		for (int i = first; i < size; i++) new_data[i] = data[i];
		for (int i = 0; i < last; i++) new_data[i] = data[i];
	}
	delete [] data;
	data = new_data;
}

template <class T>
std::ostream& operator<< (std::ostream& f, Deque<T>& arg_deque){
	Deque<T> tmp_deque;
	while(!arg_deque.is_empty()){
		T& value = arg_deque.pop_front();
		f << value << " ";
		tmp_deque.push_back(value);
	}
	while(!tmp_deque.is_empty()) arg_deque.push_back(tmp_deque.pop_front());
	return f;
}

template <class T> 
std::istream& operator>> (std::istream& f, Deque<T>& arg_deque){
	T value;
	f >> value;
	arg_deque.push_back(value);
	return f;
}

template <class T>
void read_deque(std::istream& in, Deque<T>& arg_deque){
	// int size;
	// in >> size;
	// for (int i = 0; i < size; i++) in >> arg_deque;
	while(in >> arg_deque){}
	arg_deque.pop_back();
}

template <class T>
void print_deque(std::ostream& out, Deque<T>& arg_deque, const char* msg){
	out << msg << " Deque: " << arg_deque << std::endl;
}


template <class T>
void Deque<T>::print_data() const{
	for (int i = 0; i < size; i++) std::cout << data[i];
	std::cout << '\n';
	for (int i = 0; i < size; i++) {
		if (i == first) std::cout << '!';
		else if (i == last) std::cout << '^';
		else std::cout << ' ';
	}
	std::cout << '\n';
}