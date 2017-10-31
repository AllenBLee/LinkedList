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
	List a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	Iterator it = a.begin();
	++it;
	++it;
	assert(*it == 4);
	a.insert(it, 3);
	it = a.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == a.end());
}

int main() {
	test1();
	test2();
	cout << "All tests passed." << endl;
}
