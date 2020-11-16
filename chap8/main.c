/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>
#include "Expr.h"

int main()
{
	Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
	cout << t << " = " << t.eval() << endl;
	cout << "((-5)*(3+4)) = -35" << endl;

	t = Expr("*", t, t);
	cout << t << " = " << t.eval() << endl;
	cout << "(((-5)*(3+4))*((-5)*(3+4))) = 1225" << endl;
	return 0;
}
