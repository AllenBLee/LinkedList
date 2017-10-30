#include <iostream>
#include <cassert>

#include "List.h"

using namespace std;

int main() {
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




	cout << "All tests passed." << endl;
}