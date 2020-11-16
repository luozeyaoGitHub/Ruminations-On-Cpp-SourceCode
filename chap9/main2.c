/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <stream.h>
#include "Picture.h"

char *init[] = { "Paris", "in the", "Spring" };

int main()
{
	Picture p(init, 3);
	cout << p << endl;

	Picture q = frame(p);
	cout << q << endl;

	Picture r = p | q;
	cout << r << endl;

	Picture s = q & r;
	cout << s << endl << frame(s) << endl;
	return 0;
}
