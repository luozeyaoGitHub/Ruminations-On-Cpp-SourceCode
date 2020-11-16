/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include "../chap25/String.h"
#include <iostream.h>

class Expr;

class Expr_node {
	friend class Expr;
        friend ostream& operator<<(ostream&, const Expr&);
	int use;
protected:
	Expr_node(): use(1) { }
        virtual void print(ostream&) const = 0;
        virtual int eval() const = 0;
        virtual ~Expr_node() { }
};

class Expr {
	friend class Expr_node;
	friend ostream& operator<<(ostream&, const Expr&);
	Expr_node* p;
public:
	Expr(int);
	Expr(const String&, Expr);
	Expr(const String&, Expr, Expr);
	Expr(const String&, Expr, Expr, Expr);       
	Expr(const Expr& t) { p = t.p; ++p->use; }
	~Expr() { if (--p->use == 0) delete p; }
	Expr& operator=(const Expr& t);
	int eval() const { return p->eval(); }
};

class Ternary_node: public Expr_node {
	friend class Expr;
	String op;
	Expr left;
	Expr middle;
	Expr right;
	Ternary_node(const String& a, 
		      Expr b, Expr c, Expr d):
		op(a), left(b), middle(c), right(d) { }
	void print(ostream& o) const 
	{
		o << "(" << left << " ? " <<
			middle << " : " << right << ")";
	}
	int eval() const;
};

class Unary_node: public Expr_node {
        friend class Expr;
        String op;
        Expr opnd;
        Unary_node(const String& a, Expr b):
                op(a), opnd(b) { }
        void print(ostream& o) const
                { o << "(" << op << opnd << ")"; }
	int eval() const;                          
};

class Int_node: public Expr_node {
        friend class Expr;
        int n;
        Int_node(int k): n(k) { }
        void print(ostream& o) const { o << n; }
	int eval() const { return n; }            
};

class Binary_node: public Expr_node {
	friend class Expr;
        String op;
        Expr left;
        Expr right;
        Binary_node(const String& a, Expr b, Expr c):
                op(a), left(b), right(c) { }
        void print(ostream& o) const
                { o << "(" << left << op << right << ")"; }
	int eval() const;
};
