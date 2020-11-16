/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



template<class T, class Iter>
void sum2(T& result, Iter ir)
{
	result = 0;
	while (ir.valid())
		result += ir.next();
}

#include "Reader.h"
#include <iostream.h>

int main()
{
	cout << "Enter numbers:" << endl;
	double r = 0;
	sum2(r, Reader<double>(cin));
	cout << r << endl;
	cout << 45 << endl;
	return 0;
}
