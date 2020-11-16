/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Handle.h"

Handle::Handle(): u(new int(1)), p(new Point) { }

Handle::Handle(int x, int y): u(new int(1)), p(new Point(x, y)) { }

Handle::Handle(const Point& p0): u(new int(1)), p(new Point(p0)) { }

Handle::~Handle()
{
	if (--*u == 0) {
		delete u;
		delete p;
	}
}

Handle::Handle(const Handle& h): u(h.u), p(h.p) { ++*u; }

Handle& Handle::operator=(const Handle& h)
{
	++*h.u;
	if (--*u == 0) {
		delete u;
		delete p;
	}
	u = h.u;
	p = h.p;
	return *this;
}

int Handle::x() const { return p->x(); }
int Handle::y() const { return p->y(); }

Handle& Handle::x(int x0)
{
	p->x(x0);
	return *this;
}

Handle& Handle::y(int y0)
{
	p->y(y0);
	return *this;
}
