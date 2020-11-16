/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "dirlib.h"

int Dir::read(dirent& d)
{
	if (dp) {
		dirent* r = readdir(dp);
		if (r) {
			d = *r;
			return 1;
		}
	}
	return 0;
}
