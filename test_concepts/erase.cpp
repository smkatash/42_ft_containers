#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	for (int i = 0; i < 10; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator first = v.begin();
	vector<int>::iterator last = v.begin() + 3;
	size_t	diff = last - first;
	vector<int>::iterator n_end = v.end() - diff;

	while (first != n_end) {
		cout << "Before " << *first << " -> " << first[diff] << " ";
		cout << "Diff " << diff << " ";
		*first = first[diff];
		cout << "After " << *first << endl;
		++first;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "Before " << *first << endl;
	while (first != v.end()) {
		cout << *first << " ";
		*first = 0;
		++first;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << v[i] << " ";
	}
}
