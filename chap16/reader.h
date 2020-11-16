/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>

template<class T> class Reader {
public:
	Reader(istream& is): i(is) { advance(); }
	int valid () const { return status; }
	T next() 
	{
		T result = data;
		advance();
		return result;
	}

private:
	istream& i;
	int status;
	T data;
	void advance() 
	{
		i >> data;
		status = i != 0;
	}
};
