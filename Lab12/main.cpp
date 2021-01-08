#include "tasks.h"
#include <cstdio>
#include <fstream>


int main(int arg_c, char* arg_v[]){
	

	if (arg_c < 4) std::cout << "Недостаточно параметров";
	else {
		std::ifstream f1(arg_v[1]);
		std::ifstream f2(arg_v[2]);
		std::ifstream f3(arg_v[3]);
		std::ifstream f4(arg_v[4]);

		if (! (f1.is_open() && f2.is_open() && f3.is_open() && f4.is_open()))
			std::cout << "Невозможно открыть файл" << "\n";
		else{
			task_list_1(f1, std::cout);
			std::cout << "==============================\n";
			task_list_2(f2, std::cout);
			std::cout << "==============================\n";
			task_deque_1(f3, std::cout);
			std::cout << "==============================\n";
			task_deque_2(f4, std::cout);
		}

		f1.close();
		f2.close();
		f3.close();
		f4.close();
	}
	return 0;
}