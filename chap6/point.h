/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


class Point {
public:
	Point(): xval(0), yval(0) { }
	Point(int x, int y): xval(x), yval(y) { }
	int x() const { return xval; }
	int y() const { return yval; }
	Point& x(int xv) { xval = xv; return *this; }
	Point& y(int yv) { yval = yv; return *this; }
private:
	int xval, yval;
};
