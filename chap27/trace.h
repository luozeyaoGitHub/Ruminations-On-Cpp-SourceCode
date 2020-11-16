/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <iostream.h>

class Channel {
	friend class Trace;
	ostream* trace_file;
public:
	Channel(ostream* o = &cout): trace_file(o) { }
	void reset(ostream* o) { trace_file = o; }
};

static const int debug = 0;

class Trace {
public:
	Trace(const char* s, Channel* c) 
	{
		if (debug) {
			name = s;
			cp = c;
			if (cp->trace_file)
				*cp->trace_file << "begin " 
				<< name << endl;
		}
	}

	~Trace() 
	{
		if (debug) {
			if (cp->trace_file)
				*cp->trace_file << "end " 
				<< name << endl;
		}
	}
private:
	Channel* cp;
	const char* name;
};

class Obj_trace {
public:
	Obj_trace(): ct(++count) 
	{
		cout << "Object " << ct 
		     << " constructed" << endl;
	}

	~Obj_trace() 
	{
		cout << "Object " << ct 
		     << " destroyed" << endl;
	}

	Obj_trace(const Obj_trace&): ct(++count) 
	{
		cout << "Object " << ct 
		     << " constructed" << endl;
	}

	Obj_trace& operator=(const Obj_trace&) 
	{
		return *this; 
	}

private:
	static int count;
	int ct;
};

int Obj_trace::count = 0;
