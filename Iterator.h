#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>

#include "Link.h"

class Iterator {
public:
	void operator++();
	int& operator*();
	Iterator(Link * link) : link(link) {}
	bool operator == (const Iterator & RightHandSide);

private:
	Link *link;
	friend class List;
};

#endif