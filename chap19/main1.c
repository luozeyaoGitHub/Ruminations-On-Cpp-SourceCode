/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "copy.h"
#include "copy.c"

int main()
{
	char* hello = "Hello ";
	char* world = "world";
	char message[15];
	char* p = message;

	p = copy(hello, hello+6, p);
	p = copy(world, world+5, p);
	*p = '\0';

	cout << message << endl;
	cout << "Hello world" << endl;
	return 0;
}
