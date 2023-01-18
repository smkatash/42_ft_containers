#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> x;
	for (int i = 0; i < 10; i++) {
		x.push_back(i + 1);
	}
	vector<int> y;
	for (int i = 0; i < 10; i++) {
		y.push_back(i * 2);
	}
	x.swap(y);
	cout << "X ";
	for (int i = 0; i < 10; i++) {
		cout << x[i] << " ";
	}
	cout << endl << "Y ";
	for (int i = 0; i < 10; i++) {
		cout << y[i] << " ";
	}
	cout << endl;

}