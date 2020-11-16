/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <assert.h>
#include <stdlib.h>
#include "Cluster.h"

Cluster::Cluster(): head(0) { }

Cluster::~Cluster()
{
	while (head) {
		ClusterItem* next = head->next;
		delete head;
		head = next;
	}
}

static Cluster* cp;

void* ClusterItem::operator new(size_t n, Cluster& c)
{
	cp = &c;
	return ::operator new(n);
}

ClusterItem::ClusterItem()
{
	assert(cp != 0);
	next = cp->head;
	cp->head = this;
	cp = 0;
}

void* ClusterItem::operator new(size_t)
{
	abort();
	return 0;
}
