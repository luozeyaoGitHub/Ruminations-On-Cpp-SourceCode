/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Handle2.h"
#define true 1
#define false 0

Handle::Handle(): p(new Point) { }

Handle::Handle(int x, int y): p(new Point(x, y)) { }

Handle::Handle(const Point& p0): p(new Point(p0)) { }

Handle::~Handle()
{
	if (u.only()) {
		delete p;
	}
}

Handle::Handle(const Handle& h): u(h.u), p(h.p) { }

Handle& Handle::operator=(const Handle& h)
{
	if (u.reattach(h.u))
		delete p;
	p = h.p;
	return *this;
}

int Handle::x() const { return p->x(); }
int Handle::y() const { return p->y(); }

Handle& Handle::x(int x0)
{
	if (u.makeonly())
		p = new Point(*p);
	p->x(x0);
	return *this;
}

Handle& Handle::y(int y0)
{
	if (u.makeonly())
		p = new Point(*p);
	p->y(y0);
	return *this;
}
UseCount::UseCount(): p(new int(1)) { }
UseCount::UseCount(const UseCount& u): p(u.p) { ++*p; }
UseCount::~UseCount() { if (--*p == 0) delete p; }
int UseCount::only() { return *p == 1; }

int UseCount::reattach(const UseCount& u)
{
	++*u.p;
	if (--p == 0) {
		delete p;
		p = u.p;
		return true;
	}
	p = u.p;
	return false;
}

int UseCount::makeonly()
{
	if (*p == 1)
		return false;
	--*p;
	p = new int(1);
	return true;
}
