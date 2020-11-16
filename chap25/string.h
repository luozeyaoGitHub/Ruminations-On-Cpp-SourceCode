/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


class ostream;
#include <string.h>

class String {
	friend int operator==(const String& op1, const String& op2);
	friend int operator!=(const String& op1, const String& op2);
	friend int operator<(const String& op1, const String& op2);
	friend int operator>(const String& op1, const String& op2);
	friend int operator<=(const String& op1, const String& op2);
	friend int operator>=(const String& op1, const String& op2);
	friend ostream& operator<<(ostream& os, const String& s);
public:
	String(): data(new char[1]), sz(0) { *data = 0; }
	String(char* p) { assign(p, strlen(p)); }
	~String() { delete[] data; }
	String(const String& s) { assign(s.data, s.sz); }

	int length() const { return sz; }
	void make_cstring(char* p, int len) const 
	{
		if (sz <= len)
			strcpy(p, data);
		else
			throw("Not enough memory supplied");
	}
	operator char*() { return data; }

	String& operator=(const String& s)
	{
		if (this != &s) {
			delete [] data;
			assign(s.data, s.sz);
		}
		return *this;
	}

	String& String::operator+=(const String& s);
private:
	int sz;
	char* data;

	void assign(const char* s, unsigned len) 
	{
		data = new char[len + 1];
		if (data == 0)
			throw "out of memory";
		sz = len;
		strcpy(data, s);
	}
};

String operator+(const String& op1, const String& op2);

