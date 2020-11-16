/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


int sum(int* p, int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
		result += p[i];
	return result;
}


#include <iostream.h>

int main()
{
	int x[10];
	for (int i = 0; i < 10; i++)
		x[i] = i;
	cout << sum(x, 10) << endl;
	cout << 45 << endl;
	return 0;
}
