/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


class ostream;

class Picture {

friend ostream& operator<<(ostream&, const Picture&);
friend Picture frame(const Picture&);
friend Picture operator&(const Picture&, const Picture&);
friend Picture operator|(const Picture&, const Picture&);

public:
	Picture();
	Picture(const char* const*, int);
	Picture(const Picture&);
	~Picture();
	Picture& operator=(const Picture&);

private:
	int height, width;
	char* data;
	void copyblock(int, int, const Picture&);
	char& position(int row, int col) {
		return data[row * width + col];
	}
	char position(int row, int col) const {
		return data[row * width + col];
	}
	void clear(int, int, int, int);
	void init(int, int);
	static int max(int, int);
};
