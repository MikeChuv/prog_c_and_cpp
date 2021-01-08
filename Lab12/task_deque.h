#pragma once

#include "Deque.h"

template <class T>
class TaskDeque : public Deque<T>{
	public:
		TaskDeque();
		TaskDeque(const Deque<T>& r_reque);
		TaskDeque(const TaskDeque<T>& r_task_deque);
		~TaskDeque();


}; 

template <class T>
void devide_by_condition(TaskDeque<T>& source, TaskDeque<T>& d_true, TaskDeque<T>& d_false, bool (*func)(T));

#include "task_deque.ipp"