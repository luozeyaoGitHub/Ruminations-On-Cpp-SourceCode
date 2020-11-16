/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "String.h"
#include <iostream.h>
#include <string.h>

String& String::operator+=(const String& s) 
{
	char* odata = data;
	assign(data, sz + s.sz + 1);
	strcat(data, s.data);
	delete [] odata;
	return *this;
}

String operator+(const String& op1, const String& op2) 
{
	String ret(op1);
	ret += op2;
	return ret;
}

int operator==(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) == 0);
}
int operator!=(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) != 0);
}
int operator<=(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) <= 0);
}
int operator>=(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) >= 0);
}
int operator<(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) < 0);
}
int operator>(const String& op1, const String& op2) 
{
	return (strcmp(op1.data, op2.data) > 0);
}

ostream& operator<<(ostream& os, const String& s) 
{
	return os << s.data;
}

