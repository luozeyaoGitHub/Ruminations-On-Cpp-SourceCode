/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


class ostream;
class P_Node;

class Picture {
	friend ostream& operator<<(ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture reframe(const Picture&, char, char, char);
	friend Picture operator&
		(const Picture&, const Picture&);
	friend Picture operator|
		(const Picture&, const Picture&);
	friend class String_Pic;
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
public:
	Picture();
	Picture(const char* const*, int);
	Picture(const Picture&);
	~Picture();

	Picture& operator=(const Picture&);
private:
	Picture(P_Node*);
	int height() const;                     
	int width() const;                      
	void display(ostream&, int, int) const; 
	P_Node* p;
};

class P_Node {	
	friend class Picture;
	friend Picture reframe(const Picture&, char,char,char);
protected:
	P_Node();
	virtual ~P_Node();
	virtual int height() const = 0;           
	virtual int width() const = 0;            
	virtual void display
	         (ostream&, int, int) const = 0;  
	virtual Picture reframe(char,char,char) = 0;
	static int max(int, int);
	int use;
};

class String_Pic: public P_Node {
	friend class Picture;
	String_Pic(const char* const*, int);
	~String_Pic();
	int height() const;                       
	int width() const;                        
	void display(ostream&, int, int) const;   
	Picture reframe(char, char,char);
	char** data;
	int size;
};

class Frame_Pic: public P_Node {
	friend Picture frame(const Picture&);
	Frame_Pic(const Picture&, 
		char = '+', char = '|', char = '-');
	int height() const;                       
	int width() const;                        
	void display(ostream&, int, int) const;   
	Picture reframe(char, char,char);
	Picture p;
	char corner;
	char sideborder;
	char topborder;
};

class VCat_Pic: public P_Node {
	friend Picture operator&
		(const Picture&, const Picture&);
	VCat_Pic(const Picture&, const Picture&);
	int height() const;                       
	int width() const;                       
	void display(ostream&, int, int) const;   
	Picture reframe(char, char,char);
	Picture top, bottom;
};

class HCat_Pic: public P_Node {
	friend Picture operator|
		(const Picture&, const Picture&);
	HCat_Pic(const Picture&, const Picture&);
	int height() const;                       
	int width() const;                        
	void display(ostream&, int, int) const;   
	Picture reframe(char, char,char);
	Picture left, right;
};
