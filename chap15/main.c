/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Seq.h"
#include "Seq.c"
#include <iostream.h>

template<class T>
Seq<T> merge(const Seq<T>& x, const Seq<T>& y)
{
	// if one Seq is empty, return the other
	if (!x) return y;
	if (!y) return x;

	// both are nonempty; extract the first elements
	T xh = x.hd();
	T yh = y.hd();

	// compare them
	if (xh < yh)
		return cons(xh, merge(x.tl(), y));
	return cons(yh, merge(x, y.tl()));
}

template<class T>
void split(Seq<T> x, Seq<T>& y, Seq<T>& z)
{
	while (x) {
		y.insert(x.hd());
		if (++x) {
			z.insert(x.hd());
			++x;
		}
	}
}

template<class T>
Seq<T> sort(const Seq<T>& x)
{
	if (!x || !x.tl())
		return x;

	Seq<T> p, q;

	split(x, p, q);
	return merge(sort(p), sort(q));
}

template<class T>
Seq<T> merge2(Seq<T> x, Seq<T> y)
{
	Seq<T> r;

	while (x && y) {
		if (x.hd() < y.hd()) {
			r.insert(x.hd());
			x++;
		} else {
			r.insert(y.hd());
			y++;
		}
	}

	while (x) {
		r.insert(x.hd());
		x++;
	}

	while (y) {
		r.insert(y.hd());
		y++;
	}

	r.flip();
	return r;
}

main()
{
	Seq<int> si;
	si.insert(5);
	si.insert(3);
	si.insert(9);
	si.insert(2);
	si.insert(1);
	si.insert(7);
	si.insert(8);
	si.insert(0);
	si.insert(4);
	si.insert(6);
	Seq<int> s2 = sort(si);
	while (s2)
		cout << *s2++;
	cout << endl;
	cout << "0123456789" << endl;
	return 0;
}
