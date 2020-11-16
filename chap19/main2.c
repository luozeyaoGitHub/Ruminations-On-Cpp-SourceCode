/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "Constant_iterator.h"
#include "Constant_iterator.c"
#include "copy.h"
#include "copy.c"

int  main() 
{
	int x[100];
	Constant_iterator c(0);

	copy(c, c+100, x);
	
	for (int i = 0; i < 99; i++)
		cout << x[i] << " ";
	cout << x[99] << endl;

	for (i = 0; i < 99; i++)
		cout << 0 << " ";
	cout << 0 << endl;
	return 0;
}
