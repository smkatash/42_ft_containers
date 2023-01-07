#include <iostream>
using namespace std;
#define black 1
#define red 0

int main() {
	int x = black;
	int y = red;
	cout << "X: " << boolalpha << !x << endl;
	cout << "Y: " << !y << endl;
	return 0;
}