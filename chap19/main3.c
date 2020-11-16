/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "ostream_iterator.h"
#include "Constant_iterator.h"
#include "Constant_iterator.c"
#include "copy.h"
#include "copy.c"

int main()
{
	ostream_iterator<int> oi(cout, " ");
	Constant_iterator c(42);

	copy(c, c+10, oi);
	cout << endl;
	cout << "42 42 42 42 42 42 42 42 42 42" << endl;
	return 0;
}

