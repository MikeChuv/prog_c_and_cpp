#include "task_deque.h"

template <class T>
TaskDeque<T>::TaskDeque() : Deque<T>() {}


template <class T>
TaskDeque<T>::TaskDeque(const Deque<T>& r_deque) : Deque<T>(r_deque) {}

template <class T>
TaskDeque<T>::TaskDeque(const TaskDeque<T>& r_task_deque) : Deque<T>(r_task_deque) {}


template <class T>
TaskDeque<T>::~TaskDeque() {}


template <class T>
void devide_by_condition(TaskDeque<T>& source, TaskDeque<T>& d_true, TaskDeque<T>& d_false, bool (*func)(T)){
	while(!source.is_empty()){
		T& tmp = source.pop_front();
		if (func(tmp)) d_true.push_back(tmp);
		else d_false.push_back(tmp);
	}
}