/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Iterator.h"

template<class T>
T sum(Iterator<T> ir)
{
	T result = 0;
	while (ir.valid())
		result += ir.next();
	return result;
}

#include <iostream.h>

int main()
{
	double x[10];
	for (int i = 0; i < 10; i++)
		x[i] = 3.1 * i;
	cout << sum(Iterator<double>(x, 10)) << endl;
	cout << 139.5 << endl;
	return 0;
}
