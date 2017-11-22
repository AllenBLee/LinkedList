#include <iostream>
#include <cassert>

#include "List.h"

using namespace std;

void test1() {
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

void test2() {
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
	list.pop_front();
	list.pop_back();
	Iterator it = list.begin();
	assert(*it == 1);
	list.erase(it);
	assert(list.empty() == true);
}

void test4() {
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	Iterator it = list.begin();
	assert(*it == 1);
	++it;
	list.erase(it);
	++it;
	assert(*it == 3);
	assert(list.size() == 2);
}

void test5() {
	List list;
	list.push_back(1);
	Iterator it = list.begin();
	list.insert(it, 2);
	list.push_back(3);
	assert(list.size() == 3);
	list.insert(it, 4);
	list.push_back(5);
	assert(list.size() == 5);
}

void test6() {
	List list;
	Iterator it = list.end();
	list.insert(it, 3);
	assert(list.size() == 1);
	it = list.begin();
	assert(*it == 3);
	++it;
	assert(it == list.end());
}

void test7() {
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	Iterator it = list.begin();
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(it == list.end());
}

void test8() {
	List list;
	list.push_back(1)
	Iterator it = list.begin();
	list.insert(it, 2);
	list.insert(it, 3);
	assert(*it == 3);
}

void test9() {
	List list;
	list.push_back(5);
	list.pop_back(5);
	list.pop_back(1);
	Iterator it = list.begin();
	assert(*it == nullptr);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	cout << "All tests passed." << endl;
}
