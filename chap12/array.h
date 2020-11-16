/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


template<class T> class Array {
public:
	Array(): data(0), sz(0) { }
	Array(unsigned size):
		sz(size), data(new T[size]) { }
	~Array() { delete [] data; }

	const T& operator[](unsigned n) const 
	{
		if (n >= sz || data == 0) 
			throw "Array subscript out of range";
		return data[n];
	}
	T& operator[](unsigned n) 
	{
		if (n >= sz || data == 0) 
			throw "Array subscript out of range";
		return data[n];
	}

	operator const T*() const 
	{
		return data;
	}
	operator T*() 
	{
		return data;
	}

private:
	T* data;
	unsigned sz;
	Array(const Array& a);
	Array& operator=(const Array&);
};
