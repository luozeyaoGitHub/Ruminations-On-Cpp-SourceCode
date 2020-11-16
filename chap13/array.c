/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



template <class T>
void Array_data<T>::resize(unsigned n) 
{
	if (n == sz) return;

	T* odata = data;
	data = new T[n];
	copy(odata, sz > n ? n: sz);
	delete [] odata;
	sz = n;
}

template <class T>
void Array_data<T>::copy(T* arr, unsigned n) 
{
	for (int i = 0; i < n; i++)
		data[i] = arr[i];
}

template <class T>
void Array_data<T>::grow(unsigned new_sz)
{
	unsigned nsz = sz;
	
	if (nsz == 0) nsz = 1;

	while (nsz <= new_sz) nsz *= 2;

	resize(nsz);
}

template <class T>
void Array_data<T>::clone(const Array_data& a, unsigned n)
{
	delete [] data;
	data = new T[sz = a.sz];
	copy(a.data, sz);
}

