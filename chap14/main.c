/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Array.h"
#include "Array.c"
#include <iostream.h>

main() 
{
	Array<int> a(10);
	Pointer<int> pa = a;
	Pointer<int> end = pa + 10;
	while (pa != end)
		*pa++ = 0;
	pa = a;
	while (pa != end)
		cout << *pa++;
	cout << endl;
	cout << "0000000000" << endl;
	return 0;
}
