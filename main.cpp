#include <iostream>
#include <cassert>

#include "List.h"

using namespace std;

void test1 () {
	List list;
	assert(list.empty());

	list.push_back(17);
	assert(list.empty() == false);

	list.push_front(3);
	list.push_back(10);

	Iterator it = list.begin();
	assert(*it == 3);
	++it;
	assert(*it == 17);
	++it;
	assert(*it == 10);
	++it;
	it = list.begin();
	assert(*it == 3);
	*it += 1;
}

void test2 () {
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(4);
	Iterator it = list.begin();
	++it;
	++it;
	assert(*it == 4);
	list.insert(it, 3);
	it = list.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == list.end());
}

void test3() {
	List list;
	list.push_back(1);
	list.push_back(5);
	list.push_front(7);
	list.pop_front(7);
	list.pop_back(5);
	Iterator it = list.begin();
	assert(*it == 1);
	list.erase(it, 1);
	assert(list.empty() == true);
}

int main() {
	test1();
	test2();
	test3();
	cout << "All tests passed." << endl;
}
