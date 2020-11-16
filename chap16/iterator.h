/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


template<class T> class Iterator {
public:
	Iterator(T* p, int c): data(p), len(c) { }
	int valid() const 
	{
		return len > 0;
	}
	T next() 
	{
		--len;
		return *data++;
	}
private:
	T* data;
	int len;
};
