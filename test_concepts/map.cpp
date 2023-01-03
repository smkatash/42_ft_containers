#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	map<string, int> m;
	m.insert(make_pair("ten", 10));
	m.insert(make_pair("twenty", 20));
	m.insert(make_pair("fifty", 50));
	m.insert(make_pair("one", 1));
	m.insert(make_pair("thirty", 30));
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	map<int, string> m2;
	m2.insert(make_pair(10, "ten"));
	m2.insert(make_pair(20, "twenty"));
	m2.insert(make_pair(50, "fifty"));
	m2.insert(make_pair(1, "one"));
	m2.insert(make_pair(30, "thirty"));
	map<int, string>::iterator it2;
	for (it2 = m2.begin(); it2 != m2.end(); it2++) {
		cout << it2->first << " " << it2->second << endl;
	}
}
