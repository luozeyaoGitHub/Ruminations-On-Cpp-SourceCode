/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Point.h"

class UPoint {
	
	friend class Handle;
	Point p;
	int u;

	UPoint(): u(1) { }
	UPoint(int x, int y): p(x, y), u(1) { }
	UPoint(const Point& p0): p(p0), u(1) { }
};

class Handle {
public:
	Handle();
	Handle(int, int);
	Handle(const Point&);
	Handle(const Handle&);
	Handle& operator=(const Handle&);
	~Handle();
	int x() const;
	Handle& x(int);
	int y() const;
	Handle& y(int);
private:
	UPoint* up;
};
