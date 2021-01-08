#include "tasks.h"

void task_list_1(std::istream& in, std::ostream& out){
	out << "Латинских больше половины => удалить знаки препинания" << "\n";
	TaskList<char> tl;
	read_list(in, tl);
	print_list(out, tl, "Before: ");
	int len = tl.length();
	int count_latin = tl.count_by_condition(is_latin);
	if (count_latin > len / 2) tl.delete_by_condition(is_punctuation);
	print_list(out, tl, "After: ");
}

void task_list_2(std::istream& in, std::ostream& out){
	out << "Макс больше заданного => удалить четные" << "\n";
	TaskList<int> tl;
	read_list(in, tl);
	print_list(out, tl, "Before: ");
	int val;
	std::cin >> val;
	if (tl.max() > val) tl.delete_by_condition(is_even);
	print_list(out, tl, "After: ");
}

void task_deque_1(std::istream& in, std::ostream& out){
	out << "Вещ. Разделить на положительные и неположительные" << "\n";
	TaskDeque<double> td;
	read_deque(in, td);
	print_deque(out, td, "Before: ");
	TaskDeque<double> d_true;
	TaskDeque<double> d_false;
	devide_by_condition(td, d_true, d_false, is_positive);
	print_deque(out, d_true, "Positive: ");
	print_deque(out, d_false, "Not Positive:");
}

void task_deque_2(std::istream& in, std::ostream& out){
	out << "Символы. Разделить на цифры и прочие символы" << "\n";
	TaskDeque<char> td;
	read_deque(in, td);
	print_deque(out, td, "Before: ");
	TaskDeque<char> d_true;
	TaskDeque<char> d_false;
	devide_by_condition(td, d_true, d_false, is_number);
	print_deque(out, d_true, "Number: ");
	print_deque(out, d_false, "Not Number:");
}