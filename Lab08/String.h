#pragma once

class String{
	public:
		// returns length of a string
		int length() const;

		// get n-th char
		char get_char(int n) const;

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

		// string size counstructor (empty string)
		explicit String(int size);

		// destructor
		~String();

		// cast operator string to double
		operator double () const;

	private:
		int len;
		char* data;
		void allocate(int size);
};

