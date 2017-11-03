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

	if (!head) head = newLink;

	else {
		newLink->next = head;
		head = newLink;
	}
}

void List::push_back(int x) {

	Link* newLink = new Link(x, nullptr);

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

void List::pop_front(int x) {
	Link* temp = new Link(0, nullptr);
	temp = head->next;
	delete head;
	head = temp;
}

void List::pop_back(int x) {
	assert(head != nullptr);
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Link* temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}
	tail = temp;
	tail->next = nullptr;
	delete temp->next;
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(nullptr);
}

void List::insert(Iterator it, int value) {
	assert(it.link != nullptr);
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

Iterator List::erase(Iterator it) {
	if (it.link == 0) {
		return it;  //if nothing to erase
	}
	Link * newLink = it.link->next;	//temp location of the deleted value
	int temp = it.link->value;  //stores head
	it.link->value = newLink->value; //switches head with temp
	newLink->value = temp;	//vice versa

	Link * temp2 = it.link->next->next;  //temp location of data after deleted
	it.link->next = temp2; //sets temp location = to location of data after deleted
	delete temp;
	return it;
}
