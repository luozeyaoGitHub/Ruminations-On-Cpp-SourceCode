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

main() {
	Array<int> a(10);
	for ( int i = 0; i < 10; i++)
		a.operator[](i) = i;

	Pointer<int> p(a, 4);
	*p = 42;


	for (i = 0; i < 10; i++)
		cout << a.operator[](i) << " ";
	cout << endl;
	cout << "0 1 2 3 42 5 6 7 8 9 " << endl;
	return 0;
}
