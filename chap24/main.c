/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "dirlib.h"

int main()
{
	Dir dp(".");
	dirent d;

	while (dp.read(d))
		cout << d.d_name << endl;
	return 0;
}
