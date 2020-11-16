/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


template <class T> class Array;
template <class T> class Array_data;

template<class T> class Ptr_to_const {
	friend int operator-(const Ptr_to_const<T>&, const Ptr_to_const<T>&);
	friend int operator==(const Ptr_to_const<T>&, const Ptr_to_const<T>&);
	friend int operator!=(const Ptr_to_const<T>&, const Ptr_to_const<T>&);
	friend int operator<(const Ptr_to_const<T>&, const Ptr_to_const<T>&);

	friend Ptr_to_const<T> operator-(const Array<T>&, int);
	friend Ptr_to_const<T> operator-(int, const Array<T>&);
	friend Ptr_to_const<T> operator+(const Array<T>&, int);
	friend Ptr_to_const<T> operator+(int, const Array<T>&);

	friend Ptr_to_const<T> operator-(const Ptr_to_const<T>&, int);
	friend Ptr_to_const<T> operator-(int, const Ptr_to_const<T>&);
	friend Ptr_to_const<T> operator+(const Ptr_to_const<T>&, int);
	friend Ptr_to_const<T> operator+(int, const Ptr_to_const<T>&);
public:
	Ptr_to_const(const Array<T>& a, unsigned n = 0):
		ap(a.data), 	
		sub(n) { ++ap->use; }

	Ptr_to_const(): ap(0), sub(0) { }

	Ptr_to_const(const Ptr_to_const<T>& p): 
		ap(p.ap), sub(p.sub) 
	{
		if (ap)
			++ap->use;
	}

	~Ptr_to_const() 
	{
		if (ap && --ap->use == 0)
			delete ap;
	}

	Ptr_to_const& operator=(const Ptr_to_const<T>& p) 
	{
		if (p.ap)
			++p.ap->use;
		if (ap && --ap->use == 0)
			delete ap;
		ap = p.ap;
		sub = p.sub;
		return *this;
	}

	const T& operator*() const 
	{
		if (ap == 0) 
			throw "* of unbound Ptr_to_const";
		return (*ap)[sub];
	}


	Ptr_to_const& operator++() 
	{
		++sub;
		return *this;
	}
	Ptr_to_const& operator--() 
	{
		--sub;
		return *this;
	}

	Ptr_to_const operator++(int) 
	{
		Pointer ret = *this;
		++sub;
		return ret;
	}
	Ptr_to_const operator--(int) 
	{
		Pointer ret = *this;
		--sub;
		return ret;
	}

	Ptr_to_const& operator+=(int n) 
	{
		sub += n;
		return *this;
	}
	Ptr_to_const& operator-=(int n) 
	{
		sub -= n;
		return *this;
	}
protected:
	Array_data<T>* ap;
	unsigned sub;
};

template<class T> class Pointer: public Ptr_to_const<T> {

	friend Pointer<T> operator-(Array<T>&, int);
	friend Pointer<T> operator-(int, Array<T>&);
	friend Pointer<T> operator+(Array<T>&, int);
	friend Pointer<T> operator+(int, Array<T>&);

	friend Pointer<T> operator-(const Pointer<T>&, int);
	friend Pointer<T> operator-(int, const Pointer<T>&);
	friend Pointer<T> operator+(const Pointer<T>&, int);
	friend Pointer<T> operator+(int, const Pointer<T>&);
public:
	Pointer() { }
	Pointer(Array<T>& a, unsigned n = 0):
		Ptr_to_const<T>(a,n) { }
	T& operator*() const 
	{
		if (ap == 0) 
			throw "* of unbound Ptr_to_const";
		return (*ap)[sub];
	}

	Pointer& operator++() 
	{
		++sub;
		return *this;
	}
	Pointer& operator--() 
	{
		--sub;
		return *this;
	}

	Pointer operator++(int) 
	{
		Pointer ret = *this;
		++sub;
		return ret;
	}
	Pointer operator--(int) 
	{
		Pointer ret = *this;
		--sub;
		return ret;
	}

	Pointer& operator+=(int n) 
	{
		sub += n;
		return *this;
	}
	Pointer& operator-=(int n) 
	{
		sub -= n;
		return *this;
	}
};

template<class T> class Array_data {

	friend class Array<T>;
	friend class Ptr_to_const<T>;
	friend class Pointer<T>;

	Array_data(unsigned size = 0): 
		sz(size), data(new T[size]), use(1) { }
	~Array_data() { delete [] data; }

	const T& operator[](unsigned n) const 
	{
		if (n >= sz) 
			throw "Array subscript out of range";
		return data[n];
	}
	T& operator[](unsigned n) 
	{
		if (n >= sz) 
			throw "Array subscript out of range";
		return data[n];
	}
	
	void resize(unsigned);
	void copy(T*, unsigned);
	void grow(unsigned);
	void clone(const Array_data&, unsigned);
	Array_data(const Array_data&);	// not implemented
	Array_data& operator=(const Array_data&);	// not implemented

	T* data;
	unsigned sz;
	int use;
};

template<class T> class Array {
	friend class Ptr_to_const<T>;
	friend class Pointer<T>;
public:
	Array(unsigned size): 
		data(new Array_data<T>(size)) { }
	~Array() 
	{
		if (--data->use == 0)
			delete data;
	}

	const T& operator[](unsigned n) const 
	{
		return (*data)[n];
	}
	T& operator[](unsigned n) 
	{
		return (*data)[n];
	}

	void resize(unsigned n)
	{
		data->resize(n);
	}

	void reserve(unsigned new_sz)
	{
		if (new_sz >= data->sz)
			data->grow(new_sz);
	}

	Array(const Array& a): data(new Array_data<T>(a.data->sz))
	{
		data->copy(a.data->data, a.data->sz);
	}
	Array& operator=(const Array& a)
	{
		if (this != &a)
			data->clone(*a.data, a.data->sz);
		return *this;
	}
private:
	Array_data<T>* data;
};
