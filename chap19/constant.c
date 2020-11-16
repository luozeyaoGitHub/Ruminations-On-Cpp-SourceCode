/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



Constant_iterator::Constant_iterator(int k): n(k) { }

int Constant_iterator::operator*() const { return n; }

Constant_iterator& Constant_iterator::operator++()
{
	++count;
	return *this;
}

Constant_iterator Constant_iterator::operator++(int)
{
	Constant_iterator r = *this;
	++count;
	return r;
}

Constant_iterator 
operator+(const Constant_iterator& p, int n)
{
	Constant_iterator r = p;
	r.count += n;
	return r;
}

Constant_iterator 
operator+(int n, const Constant_iterator& p) 
{
	return p + n;
}

int operator==(const Constant_iterator& p,
	       const Constant_iterator& q)
{
	return p.count == q.count && p.n == q.n;
}

int operator!=(const Constant_iterator& p,
	       const Constant_iterator& q)
{
	return !(p == q);
}
