/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <dirent.h>

class Dir_offset {
	friend class Dir;
private:
	long l;
	Dir_offset(long n) { l = n; }
	operator long() { return l; }
};

class Dir {
public:
	Dir(const char* file): dp(opendir(file)) { }
	~Dir() { if (dp) closedir(dp); }
	int read(dirent&);
	void seek(Dir_offset pos) { if (dp) seekdir(dp, pos); }
	Dir_offset tell() const { if (dp) return telldir(dp); else return -1; }
private:
	DIR* dp;
	Dir(const Dir&);	// not implemented
	Dir& operator=(const Dir&);	// not implemented
};
