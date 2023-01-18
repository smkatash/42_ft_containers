#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // initialize a vector
    vector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;

	// declare iterators
	vector<int>::iterator it1, it2, temp;
	// inititalize the iterators
	it1 = v.begin();   // will point to the first element, i.e. 1
	it2 = v.end() - 1;  // will point to the last element, i.e. 5
	// dereference and print iterators before swapping them
	cout << "Before Swapping" << endl;
	cout << "Dereferenced iterator 1: " << *it1 << " " ;
	cout << "\n";  
	cout << "Dereferenced iterator 2: " << *it2;
	cout << "\n\n";

	// swap the iterators
	temp = it1;
	it1 = it2;
	it2 = temp;
	// dereference and print iterators after swapping them
	cout << "Before Swapping" << endl;
	cout << "Dereferenced iterator 1: " << *it1 << " " ;
	cout << "\n";  
	cout << "Dereferenced iterator 2: " << *it2;
	cout << "\n\n";

	//check for equal operator
	it1 = it2;
	if (it1 == it2)
		cout << "Iterators are equal" << endl;
	else
		cout << "Iterators are Not equal" << endl;

	return 0;
} 