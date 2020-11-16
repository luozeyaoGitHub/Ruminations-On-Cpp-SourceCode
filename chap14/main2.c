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
	Array<int> ai(10);

	for (int i = 0; i < 10; i ++)
		ai.operator[](i) = i;
	
	Pointer<int> p = ai;

	while (p != ai + 10) cout << *p++;
	cout << endl;
	cout << "0123456789" << endl;
	return 0;
}
