#pragma once

#include <stdio.h>

class ListException{
	public:
		ListException();
		ListException(const char* reason) : message("Caught!\n"){};
		virtual void print_error() const;
	protected:
		const char* message;
};

class EmptyList : public ListException{
	public:
		EmptyList();
		EmptyList(const char* reason) : details(reason) {
			message = reason;
		};
		void print_error() const override;
	private:
		const char* details;
};

class IndexOutOfRange : public ListException{
	public:
		IndexOutOfRange();
		IndexOutOfRange(const char* reason, int index) 
			: details(reason), idx(index) {
			message = reason;
		};
		void print_error() const override;
	private:
		int idx;
		const char* details;
};




class DequeException{
	public:
		DequeException();
		DequeException(const char* reason) : message("Caught!\n"){};
		virtual void print_error() const;
	protected:
		const char* message;
};

class EmptyDeque : public DequeException{
	public:
		EmptyDeque();
		EmptyDeque(const char* reason) : details(reason) {
			message = reason;
		};
		void print_error() const override;
	private:
		const char* details;
};

//#include "Exceptions.cpp"