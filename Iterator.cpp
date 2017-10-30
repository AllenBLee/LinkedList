#include <iostream>

#include "Iterator.h"
#include "List.h"
#include "Link.h"

void Iterator::operator++() {
	link = link->next;
}

int& Iterator::operator*() {
	return link->value;
}

bool Iterator::operator == (const Iterator & RightHandSide) {
	return link == RightHandSide.link;
}
