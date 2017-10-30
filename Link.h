#ifndef LINK_H
#define LINK_H

#include <iostream>

class Link {
public:
	Link(int value, Link* next) : value(value), next(next) {}
	Link* next;
	int value;

private:
	friend class list;
	friend class Iterator;
};

#endif