#pragma once
#include "Exceptions.h"

class String{
	public:
		// returns length of a string
		int length() const;

		// get n-th char
		char get_char(int n) const ;

		// print string
		void print() const;

		// change n-th char
		void change_char(int n, char c);

		// one parameter + default coustructor 
		String(const char* in = "\0");

		// copy constructor
		String(const String& source, int n);

		// cast coonstructor double to string
		String(double number);

		explicit String(int size);

		// destructor
		~String();

		// cast operator string to double
		//operator double () const;



		String & operator = (const String& s);

		friend bool operator < (const String& s1, const String& s2);
		friend bool operator > (const String& s1, const String& s2);
		friend bool operator == (const String& s1, const String& s2);
		friend bool operator != (const String& s1, const String& s2);

		char & operator [] (int index);
		const char & operator [] (int index) const;

		static int compare(char* , char*);

		/*
		String operator + (const String& s) const;
		String operator - (const String& s) const;
		*/

		friend String operator + (const String& s1, const String& s2);
		friend String operator - (const String& s1, const String& s2);

		void operator += (char c);
		void operator += (const String& s);

	private:
		int len;
		char* data;
		void allocate(int size);
};


