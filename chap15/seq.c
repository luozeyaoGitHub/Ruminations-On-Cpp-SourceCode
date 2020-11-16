/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */



template<class T> Seq<T> Seq<T>::tl() const
{
	if (item)
		return Seq<T>(item->next, len-1);
	else
		throw "tl of an empty Seq";
}

template <class T> 
Seq_item<T>::Seq_item(const T& t, Seq_item<T>* s):
	use(1), data(t), next(s)
{
	if (s)
		s->use++;
}

template<class T> T Seq<T>::hd() const
{
	if (item)
		return item->data;
	else
		throw "hd of an empty Seq";
}


template<class T> 
Seq<T>& Seq<T>::operator=(const Seq<T>& s)
{
	if (s.item)
		s.item->use++;
	destroy(item);
	item = s.item;
	len = s.len;
	return *this;
}

template<class T> 
void Seq<T>::destroy(Seq_item<T>* item)
{
	while (item && --item->use == 0) {
		Seq_item<T>* next = item->next;
		delete item;
		item = next;
	}
}

template <class T>
Seq<T>& Seq<T>::operator++()
{
	if (item) {
		Seq_item<T>* p = item->next;
		if (p)
			p->use++;
		if (--item->use == 0)
			delete item;
		item = p;
	}
	return *this;
}

template <class T>
Seq<T> Seq<T>::operator++(int)
{
	Seq<T> ret = *this;
	if (item) {
		--item->use;
		item = item->next;
		if (item)
			item->use++;
	}
	return ret;
}


template <class T>
Seq<T>& Seq<T>::insert(const T& t)
{
	item = new Seq_item<T>(t, item);
	return *this;
}


template<class T> Seq_item<T>* Seq<T>::owntail()
{
	if (item == 0)
		return 0;
	Seq_item<T>* i = item;
	Seq_item<T>** p = &item;

	while (i->use == 1) {
		if (i->next == 0)
			return i;
		p = &i->next;
		i = i->next;
	}
	*p = new Seq_item<T> (i->data);
	--i->use;
	i = i->next;
	Seq_item<T>* j = *p;
	while (i) {
		j->next = new Seq_item<T> (i->data);
		i = i->next;
		j = j->next;
	}

	return j;
}

template<class T> Seq<T>& Seq<T>::flip()
{
	if (item) {
		Seq_item<T>* k = owntail();
		Seq_item<T>* curr = item;
		Seq_item<T>* behind = 0;

		do {
			Seq_item<T>* ahead = curr->next;
			curr->next = behind;
			behind = curr;
			curr = ahead;
		} while (curr);

		item = k;
	}

	return *this;
}

template<class T>
int operator==(const Seq<T>& op1, const Seq<T>& op2)
{
	if (op1.length() != op2.length())
		return 0;
	Seq_item<T>*p = op1.item;
	Seq_item<T>*q = op2.item;
	
	while (p != q) {
		assert (p != 0 && q != 0);
		if (*p++ != *q++)
			return 1;
	}

	return 0;
}

template<class T>
Seq<T> cons(const T& t, const Seq<T>& s)
{
	return Seq<T>(t, s);
}
