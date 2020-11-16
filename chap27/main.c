/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Trace.h"

template<class T> class Array {
public:
	Array(int n = 0): data(new T[n]), sz(n) { }
	Array(const Array& a) { init(a.data, a.sz); }
	~Array() { delete [] data; }

	Array& operator=(const Array& a) 
	{
		if (this != &a) {
			delete[] data;
			init(a.data, a.sz);
		}
		return *this;
	}

	T& operator[](unsigned n) 
	{
		return data[n];
	}

private:
	T* data;
	int sz;
	void init(T*, int);
};

template<class T> void Array<T>::init(T* p, int n)
{
	sz = n;
	data = new T[n];
	for (int i = 0; i < sz; i++)
		data[i] = p[i];
}

int main()
{
	Array<Obj_trace> x(3);
	Array<Obj_trace> y = x;
	x = y;
	return 0;
}
