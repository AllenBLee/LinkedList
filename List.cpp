#include <iostream>
#include <cassert>

#include "List.h"

List::~List() {
	head = nullptr;
	delete head;
}

int List::size() {
	int count = 0;
	Link* temp = head;
	while (temp != nullptr) {
		++count;
		temp = temp->next;
	}
	return count;
}

bool List::empty() const {
	if (!head) return true;
	else return false;
}

void List::push_front(int x) {
	Link* newLink = new Link(x, nullptr);
	Link *newTail = head;
	if (!head) head = newLink;
	else {
		newLink->next = head;
		head = newLink;
	}
	while (newTail->next != nullptr) {
		newTail = newTail->next;
	}
	tail = newTail;
}

void List::push_back(int x) {
	Link* newLink = new Link(x, nullptr);
	tail = newLink;
	if (!head) head = newLink;
	else {
		bool flag = true;
		Link* temp = head;
		while (flag == true)
		{
			if (!(temp->next)) flag = false;
			else temp = temp->next;
		}
		temp->next = newLink;
	}
}

void List::pop_front() {
	Link* temp = new Link(0, nullptr);
	temp = head->next;
	delete head;
	head = temp;
}

void List::pop_back() {
	Link* end = head;
	while (end->next != nullptr) {
		end = end->next;
	}
	Link* newTail = head;
	while (newTail->next != end) {
		newTail = newTail->next;
	}
	newTail->next = nullptr;
	tail = newTail;
	end = nullptr;
	delete end;
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(nullptr);
}

void List::insert(Iterator it, int value) {
	if (it.link == head) {
		head = new Link(value, head);
		return;
	}
	Link * prev = head;
	while (prev->next != it.link) {
		prev = prev->next;
	}
	prev->next = new Link(value, it.link);
}

void List::erase(Iterator it) {
	if (it.link == head) {
		head = it.link->next;
	}
	else {
		Link * newNode = head;
		while (newNode->next != it.link) {
			newNode = newNode->next;
		}
		newNode->next = it.link->next;
	}
	it = nullptr;
	delete it.link;
}
