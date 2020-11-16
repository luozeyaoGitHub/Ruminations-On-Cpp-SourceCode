/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Handle.h"

Handle::Handle(): up(new UPoint) { }

Handle::Handle(int x, int y): up(new UPoint(x, y)) { }

Handle::Handle(const Point& p): up(new UPoint(p)) { }

Handle::~Handle()
{
	if (up->u == 0)
		delete up;
}

Handle::Handle(const Handle& h): up(h.up) { ++up->u; }

Handle& Handle::operator=(const Handle& h)
{
	++h.up->u;
	if (--up->u == 0)
		delete up;
	return *this;
}

int Handle::x() const { return up->p.x(); }
int Handle::y() const { return up->p.y(); }

Handle& Handle::x(int x0)
{
	up->p.x(x0);
	return *this;
}

Handle& Handle::y(int y0)
{
	up->p.y(y0);
	return *this;
}
