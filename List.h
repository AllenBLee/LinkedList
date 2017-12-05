#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "List.h"
#include "Iterator.h"
#include "Link.h"

class List {
public:
	List() {
		head = nullptr;
		tail = nullptr;
	}
	~List();
	int size();
	bool empty() const;
	void push_front(int x);
	void push_back(int x);
	void pop_front();
	void pop_back();
	Iterator begin();
	Iterator end();
	void insert(Iterator it, int value);
	void erase(Iterator it);

private:
	Link* head;
	Link* tail;
	int count;
};

#endif
