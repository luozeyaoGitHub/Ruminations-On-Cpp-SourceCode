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
#include <iostream.h>
#include "Iterator.h"

int main()
{
	int x[10];
	for (int i = 0; i < 10; i++)
		x[i] = i;
	int r;
	sum2(r, Iterator<int>(x, 10));
	cout << r << endl;
	cout << 45 << endl;
	return 0;
}
