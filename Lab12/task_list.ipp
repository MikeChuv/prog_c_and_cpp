#include "task_list.h"

template <class T>
TaskList<T>::TaskList() : List<T>() {}

template <class T>
TaskList<T>::TaskList(const List<T>& r_list) : List<T>(r_list) {}

template <class T>
TaskList<T>::TaskList(const TaskList<T>& r_task_list) : List<T>(r_task_list) {}

template <class T>
TaskList<T>::~TaskList() {}

template <class T>
void TaskList<T>::delete_by_condition(bool (*func)(T)){
	if(this->is_empty()) throw EmptyList("delete_by_condition()");
	Node<T>* cur = this->get_first();
	int i = 0;
	while(cur && i < this->length()) {
		if (func(cur->get_value())) {
			this->delete_current(i);
			if (i < this->length()) cur = this->get_node(i);
		}
		else{
			cur = cur->next_node();
			i++;
		}
	}
}

template <class T>
int TaskList<T>::count_by_condition(bool (*func)(T)){
	if (this->is_empty()) throw EmptyList("count_by_condition()");
	int result = 0;
	for(Node<T>* cur = this->get_first(); cur != this->get_last(); cur = cur->next_node()){
		if (func(cur->get_value())) result++;
	}
	return result;
}

template <class T>
T TaskList<T>::max() const{
	if (this->is_empty()) throw EmptyList("max()");
	T result = this->get_first()->value;	
	for(Node<T>* cur = this->get_first(); cur; cur = cur->next_node()){
		if (cur->get_value() > result) result = cur->get_value();
	}
	return result;	
}