/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "Picture.h"

char *init[] = { "Paris", "in the", "Spring" };

int main()
{
	Picture p(init, 3);
	cout << p << endl;
	Picture q = p;
	cout << q << endl;
	return 0;
}
