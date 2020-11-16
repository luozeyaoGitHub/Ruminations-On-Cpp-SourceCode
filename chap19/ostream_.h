/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#ifndef ostream_it
#define ostream_it

template<class T>
class ostream_iterator {
public:
	ostream_iterator(ostream& os, const char* s):
		strm(&os), str(s) { }
	ostream_iterator& operator++() { return *this; }
	ostream_iterator& operator++(int) { return *this; }
	ostream_iterator& operator*() { return *this; }
	ostream_iterator& operator=(const T& t) 
	{
		*strm << t << str;
		return *this;
	}
private:
	ostream* strm;
	const char* str;
};

#endif
