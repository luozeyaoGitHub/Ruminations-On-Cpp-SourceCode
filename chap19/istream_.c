/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



template<class T>
int operator==(istream_iterator<T>& p, istream_iterator<T>& q)
{
	if (p.eof && q.eof)
		return 1;
	if (!p.eof && !q.eof)
		return &p == &q;
	p.fill(); q.fill();
	return p.eof == q.eof;
}

template<class T>
int operator!=(istream_iterator<T>& p, istream_iterator<T>& q)
{
	return !(p == q);
}

