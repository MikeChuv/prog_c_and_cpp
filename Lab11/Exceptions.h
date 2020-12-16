#pragma once


class StringException{
	public:
		StringException();

		StringException(const char* reason) : message("Caught\n") {};

		virtual void print_error() const;

	protected:
		const char* message;
};


class IndexOutOfRange : public StringException{
	public:
		IndexOutOfRange(int index, const char* reason) 
			: details(reason), idx(index){
			message = reason;
		};
		
		void print_error() const override;
	private:
		int idx;
		const char* details;
};


class BadAlloc : public StringException{
	public:
		BadAlloc(int size, const char* reason) 
			: details(reason), inv_size(size) {
			message = reason;
		};
		
		void print_error() const override;
	private:
		int inv_size;
		const char* details;
};
// IndexOutOfRange
// вычитание из пустой строки ??
// BadAlloc


