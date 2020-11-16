/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "Expr.h"

Expr::Expr(int n)
{
        p = new Int_node(n);
}

Expr::Expr(const String& op, Expr t)
{
        p = new Unary_node(op, t);
}

Expr::Expr(const String& op, Expr left, Expr right)
{
        p = new Binary_node(op, left, right);
}

Expr::Expr (const String& op, Expr left, Expr middle, Expr right)
{
	p = new Ternary_node(op, left, middle, right);
}

Expr&
Expr::operator=(const Expr& rhs) 
{
	rhs.p->use++;
	if (--p->use == 0) 
		delete p;
	p = rhs.p;
	return *this;
}

ostream&
operator<<(ostream& o, const Expr& t)
{
        t.p->print(o);
        return o;
}

int
Unary_node::eval() const
{
	if (op == "-")
                return -opnd.eval();
        throw "error, bad op " + op + " in UnaryNode";
}

int
Binary_node::eval() const
{
        int op1 = left.eval();
        int op2 = right.eval();

        if (op == "-")  return op1 - op2;
        if (op == "+")  return op1 + op2;
        if (op == "*")  return op1 * op2;
        if (op == "/" && op2 != 0)  return op1 / op2;

        throw "error, bad op " + op + " in BinaryNode";
}

Ternary_node::eval() const
{
	if (left.eval())
		return middle.eval();
	else
		return right.eval();
}

