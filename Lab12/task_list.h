#pragma once

#include "List.h"

template <class T>
class TaskList : public List<T>{
	public:
		TaskList();
		TaskList(const List<T>& r_list);
		TaskList(const TaskList<T>& r_task_list);
		~TaskList();

		void delete_by_condition(bool (*func)(T));
		int count_by_condition(bool (*func)(T));

		T max() const;
};

#include "task_list.ipp"