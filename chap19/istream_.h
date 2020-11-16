/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#ifndef istream_it
#define istream_it

#include <iostream.h>
#include <assert.h>

template<class T>
class istream_iterator {
private:
	T buffer;
	istream* strm;
	int full;
	int eof;
public:
	istream_iterator(istream& is):
		strm(&is), full(0), eof(0) { }

	istream_iterator():
		strm(0), full(0), eof(1) { }

	istream_iterator& operator++() 
	{
		full = 0;
		return *this;
	}

	istream_iterator operator++(int) 
	{
		istream_iterator r = *this;
		full = 0;
		return r;
	}

private:
	void fill() 
	{
		if (!full && !eof) {
			if (*strm >> buffer)
				full = 1;
			else
				eof = 1;
		}
	}
public:
	T operator*() 
	{
		fill();
		assert(full);
		return buffer;
	}
friend int operator==(istream_iterator<T>&, istream_iterator<T>&);
friend int operator!=(istream_iterator<T>&, istream_iterator<T>&);
};

#endif
