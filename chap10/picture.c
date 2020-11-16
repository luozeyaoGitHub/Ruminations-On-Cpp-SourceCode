/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Picture.h"
#include <iostream.h>
#include <string.h>

Picture::Picture(const Picture& orig): p(orig.p)
{
	orig.p->use++;
}

Picture::~Picture()
{
	if (--p->use == 0)
		delete p;
}

Picture& Picture::operator=(const Picture& orig) 
{
	orig.p->use++;
	if (--p->use == 0)
		delete p;
	p = orig.p;
	return *this;
}

P_Node::~P_Node() { }

P_Node::P_Node(): use(1) { }

Picture::Picture(const char* const* str, int n): 
	p(new String_Pic(str, n)) { }

String_Pic::String_Pic(const char* const* p, int n): 
	data(new char* [n]), size(n)
{
	for (int i = 0; i < n; i++) {
		data[i] = new char[strlen(p[i])+1];
		strcpy(data[i], p[i]);
	}
}

String_Pic::~String_Pic()
{
	for (int i = 0; i < size; i++)
		delete[] data[i];
	delete[] data;
}

Frame_Pic::Frame_Pic(const Picture& pic, char c, char s, char t): 
	p(pic), corner(c), sideborder(s), topborder(t) { }

Picture::Picture(P_Node* p_node): p(p_node) { }

Picture frame(const Picture& pic) 
{
	return new Frame_Pic(pic);
};

VCat_Pic::VCat_Pic(const Picture& t, const Picture& b):
	top(t), bottom(b) { }

Picture operator&(const Picture& t, const Picture& b) 
{
	return new VCat_Pic(t, b);
};

HCat_Pic::HCat_Pic(const Picture& l, const Picture& r):
	left(l), right(r) { }

Picture operator|(const Picture& l, const Picture& r) 
{
	return new HCat_Pic(l, r);
};

int Picture::height() const
{
	return p->height();
}

int Picture::width() const
{
	return p->width();
}

void Picture::display(ostream& o, int x, int y) const
{
	p->display(o, x, y);
}

ostream& operator<<(ostream& os, const Picture& picture) 
{
	int ht = picture.height();
	for (int i = 0; i < ht; i++) {
		picture.display(os, i, 0);
		os << endl;
	}
	return os;
}

int P_Node::max(int x, int y)
{
	return x > y ? x: y;
}

int String_Pic::height() const 
{
	return size;
}

int String_Pic::width() const 
{
	int n = 0;
	for (int i = 0; i < size; i++) {
		n = P_Node::max(n, strlen(data[i]));
	}
	return n;
}

static void pad(ostream& os, int x, int y)
{
	for (int i = x; i < y; i++)
		os << " ";
}

void 
String_Pic::display(ostream& os, int row, int width) const 
{
	int start = 0;
	if (row >= 0 && row < height()) {
		os << data[row];
		start = strlen(data[row]);
	}
	pad(os, start, width);
}

int Frame_Pic::height() const
{
	return p.height() + 2;
}

int Frame_Pic::width() const
{
	return p.width() + 2;
}

void Frame_Pic::display(ostream& os, int row, int wd) const 
{
	if (row < 0 || row >= height())
		// \f2out of range\fP
		pad(os, 0, wd);
	else {
		if (row == 0 || row == height() - 1) {
			// \f2top or bottom border\fP
			os << corner;
			int i = p.width();
			while (--i >= 0)
				os << topborder;
			os << corner;
		} else {
			// \f2interior row\fP
			os << sideborder;
			p.display(os, row - 1, p.width());
			os << sideborder;
		}
		pad(os, width(), wd);
	}
}

int VCat_Pic::height() const
{
	return top.height() + bottom.height();
}

int VCat_Pic::width() const
{
	return P_Node::max(top.width(), bottom.width());
}

int HCat_Pic::height() const
{
	return P_Node::max(left.height(), right.height());
}

int HCat_Pic::width() const
{
	return left.width() + right.width();
}

void VCat_Pic::display(ostream& os, int row, int wd) const 
{
	if (row >= 0 && row < top.height())
		top.display(os, row, wd);
	else if (row < top.height() + bottom.height())
		bottom.display(os, row - top.height(), wd);
	else
		pad(os, 0, wd);
}

void HCat_Pic::display(ostream& os, int row, int wd) const 
{
	left.display(os, row, left.width());
	right.display(os, row, right.width());
	pad(os, width(), wd);
}

Picture reframe (const Picture& pic, char c, char s, char t)
{
        return pic.p->reframe(c,s,t);
}

Picture String_Pic::reframe(char, char, char) 
{
        use++;
        return this;  
}

Picture VCat_Pic::reframe(char c, char s, char t) 
{
        return new VCat_Pic(
		::reframe(top,c,s,t), 
		::reframe(bottom,c,s,t)
	);
}

Picture HCat_Pic::reframe(char c, char s, char t) 
{
        return new HCat_Pic(
		::reframe(left,c,s,t), 
		::reframe(right,c,s,t)
	);
}

Picture Frame_Pic::reframe(char c, char s, char t) 
{
        return new Frame_Pic(::reframe(p,c,s,t), c, s, t);
}

