/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



template <class T> class Seq;

template <class T> class Seq_item {
	friend class Seq<T>;
	int use;
	const T data;
	Seq_item* next;
	Seq_item(const T& t, Seq_item* s);
	Seq_item(const T& t): use(1), data(t), next(0) { }
};

template<class T> class Seq {
	friend int operator==(const Seq<T>&, const Seq<T>&);
public:
	Seq(): item(0), len(0) { }
	Seq(const T& t, const Seq& x): item(new Seq_item<T>(t, x.item)), len(x.len+1) { }
	Seq(const Seq& s): item(s.item), len(s.len) { if (item) item->use++; }
	Seq(Seq_item<T>* s, unsigned l): item(s), len(l) { if (s) s->use++; }

	~Seq() { destroy(item); }

	Seq& operator=(const Seq&);   
	T hd() const;
	Seq tl() const;
	operator int() const { return item != 0; }
	//operator bool() const { return item; }
	void destroy(Seq_item<T>*);
	Seq<T>& operator++();
	Seq<T>  operator++(int);
	T operator*() { return hd(); }
	Seq<T>& insert(const T&);
	Seq_item<T>* owntail();
	Seq<T>& flip();
	unsigned length() { return len; }
private:
	Seq_item<T>* item;            
	unsigned len;
};

template<class T> Seq<T> cons(const T& t, const Seq<T>& s);
