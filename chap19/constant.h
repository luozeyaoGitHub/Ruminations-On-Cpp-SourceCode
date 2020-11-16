/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#ifndef Constant_it
#define Constant_it

class Constant_iterator {
public:
	Constant_iterator(int=0);
	int operator*() const;
	Constant_iterator& operator++();
	Constant_iterator operator++(int);
private:
	int n;
	int count;
	friend int operator==(const Constant_iterator&, 
			      const Constant_iterator&);
	friend int operator!=(const Constant_iterator&, 
			      const Constant_iterator&);
	friend Constant_iterator operator+
		(const Constant_iterator&, int);
	friend Constant_iterator operator+
		(int, const Constant_iterator&);
};

#endif
