/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "ostream_iterator.h"
#include "istream_iterator.h"
#include "istream_iterator.c"
#include "copy.h"
#include "copy.c"

int main()
{
	ostream_iterator<int> output(cout, " ");
	istream_iterator<int> input(cin);
	istream_iterator<int> eof;

	copy(input, eof, output);

	cout << endl << "10 20 30 40" << endl;
	return 0;
}
