#include "List.h"


template <class T>
List<T>::List() : first(nullptr), last(nullptr) {}

template <class T>
List<T>::List(const List<T>& val){
	Node<T>* current = val->first;
	while(current != nullptr){
		this->push_back(current->value);
		current = current->next;
	}
}

template <class T>
List<T>::~List(){
	while(!is_empty()){
		pop_front();
	}
}

template <class T>
int List<T>::length() const{
	int len = 0;
	Node<T>* current = first;
	while(current != nullptr){
		len++;
		current = current->next;
	}
	return len;
}

template <class T>
bool List<T>::is_empty() const {
	return first == nullptr;
}





template <class T>
void List<T>::push_front(const T& value){
	if (is_empty()){
		first = last = new Node<T>(value, nullptr);
	}
	else{
		first = new Node<T>(value, first);
	}
}

template <class T>
void List<T>::push_back(const T& value){
	if (is_empty()){
		first = last = new Node<T>(value, nullptr);
	}
	else{
		last->next = new Node<T>(value, nullptr);
		last = last->next;
	}
}

template <class T>
void List<T>::push_after(int index, const T& value){
	if (is_empty()){
		first = last = new Node<T>(value, nullptr);
	}
	else{
		try{
			Node<T>* cur = get_node(index);
			Node<T>* result = new Node<T>(value, cur->next);
			cur->next = result;
		}
		catch(const IndexOutOfRange& exception){
			std::cout << "push_after() "; 
			exception.print_error();
		}

	}
}




template <class T>
void List<T>::delete_front(){
	if (!is_empty()){
		Node<T>* old_first = first;
		first = first->next;
		delete old_first;
	}
	else throw EmptyList("delete_front()");
}

template <class T>
void List<T>::delete_back(){
	if (!is_empty()){
		Node<T>* cur = first;
		while(cur->next != last) cur = cur->next;
		Node<T>* old_last = last;
		last = cur;
		last->next = nullptr;
		delete old_last;
	}
	else throw EmptyList("delete_back()");
}

template <class T>
void List<T>::delete_current(int index){
	if (is_empty()) throw EmptyList("delete_back()");
	try{
		Node<T>* cur = get_node(index);
		if (cur == first && cur == last){
			delete cur;
			first = nullptr;
			last = nullptr;
		}
		else if (cur == first){
			delete_front();
		}
		else if (cur == last){
			delete_back();
		}
		else{
			Node<T>* prev = get_node(index - 1);
			prev->next = cur->next;
			delete cur;
		}
	}
	catch(const IndexOutOfRange& exception){
		std::cout << "delete_current() "; 
		exception.print_error();
	}
}


template <class T>
T List<T>::pop_front(){
	if(!is_empty()){ 
		Node<T>* tmp = first->next;
		T val = first->value;
		delete first;
		first = tmp;
		return val;
	}
	else throw EmptyList("pop_front()");
}


template <class T>
T List<T>::pop_back(){
	if(!is_empty()){ 
		T val = last->value;
		Node<T>* cur = first;
		while(cur->next != last) cur = cur->next;
		delete last;
		cur->next = nullptr;
		last = cur;
		return val;
	}
	else throw EmptyList("pop_back()");
}

template <class T>
T List<T>::pop_current(int index){
	if(!is_empty()){ 
		try{
			Node<T>* cur = get_node(index);
			Node<T>* prev = get_node(index - 1);
			prev->next = cur->next;
			T result = cur->value;
			delete cur;
			return result;
		}
		catch(const IndexOutOfRange& exception){
			std::cout << "pop_current() "; 
			exception.print_error();
		}
	}
	else throw EmptyList("pop_current()");
}

template <class T>
Node<T> * List<T>::get_node(int index) const{
	Node<T>* cur = first;
	// возможно лучше сравнивать с length
	for(int i = 0; i < index; i++){
		if(cur->next == nullptr) throw IndexOutOfRange("get_node()", index);
		cur = cur->next;
	}
	return cur;
}

template <class T>
T& List<T>::operator [] (int index){
	Node<T>* cur = first;
	for(int i = 0; i < index; i++){
		if(cur->next == nullptr) throw IndexOutOfRange("operator []", index);
		cur = cur->next;
	}
	return cur->value;
}

template <class T>
const T& List<T>::operator [] (int index) const{
	Node<T>* cur = first;
	for(int i = 0; i < index; i++){
		if(cur->next == nullptr) throw IndexOutOfRange("operator []", index);
		cur = cur->next;
	}
	return cur->value;
}

template <class T>
bool List<T>::operator == (const List& list) const{
	if (length() != list.length()) return false;
	else{
		Node<T>* l_cur = first;
		Node<T>* r_cur = list.first;
		for (int i = 0; i < length(); i++){
			if (l_cur->value != r_cur->value) return false;
			else {
				l_cur = l_cur->next;
				r_cur = r_cur->next;
			}
		}
		return true;
	}
}

template <class T>
List<T>& List<T>::operator = (const List& list){
	this -> ~List();
	//for (int i = 0; i < list.length(); i++) push_back(list[i]);
	Node<T>* cur = list.first;
	while(cur != nullptr) {
		push_back(cur->value);
		cur = cur->next;
	}
}

template <class T>
std::ostream& operator<< (std::ostream& f, const List<T>& arg_list){
	for (int i = 0; i < arg_list.length(); i++){
		f << arg_list[i] << " ";
	}
	return f;
}

template <class T>
std::istream& operator>> (std::istream& f, List<T>& arg_list){
	T value;
	f >> value;
	arg_list.push_back(value);
	return f;
}

template <class T>
void read_list(std::istream& in, List<T>& arg_list){
	// unsigned int size = 0;
	// in >> size;
	// for (unsigned int i = 0; i < size; i++) in >> arg_list;
	while(in >> arg_list){}
	arg_list.pop_back();
}

template <class T>
void print_list(std::ostream& out, const List<T>& arg_list, const char* msg){
	out << msg << " List: " << arg_list << std::endl;
}
