#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

int main() {
	vector<int> v;

	//============================pop_back() ============//
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	for (int i = 0; i < 10; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	// cout << "Size " << v.size() << endl;
	// v[v.size() - 1] = 0;
	// for (int i = 0; i < 10; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << "Size " << v.size() - 1 << endl;
	//============================push_back() ============//
	if (17 > v.capacity()) {
		cout << "full" << endl;
		v.reserve(17 + 1);
	}
	cout << v.size() << " " << v.capacity() << endl;
	std::allocator<int> alloc;
	vector<int>::iterator	it = v.end() + 7;
	int *p = &(*it);
	alloc.construct(&(*it), 11);
	//alloc.construct(p, 11);
	cout << *p << endl;
	for (vector<int>::iterator it = v.begin(); it < v.end() + 8; it++) {
		cout << *it << " ";
	}
}
