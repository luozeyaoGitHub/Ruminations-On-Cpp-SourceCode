/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


#include <stdlib.h>

class Cluster {
	friend class ClusterItem;
public:
	Cluster();
	~Cluster();
private:
	ClusterItem* head;	
	Cluster(const Cluster&);
	Cluster& operator=(const Cluster&);
};

class ClusterItem {
	friend class Cluster;
public:
	void* operator new(size_t, Cluster&);
	ClusterItem();
protected:
	virtual ~ClusterItem() { }
private:
	ClusterItem* next;
	void* operator new(size_t);
	ClusterItem(const ClusterItem&);
	ClusterItem& operator=(const ClusterItem&);
};
