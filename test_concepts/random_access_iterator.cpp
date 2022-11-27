#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    // initialize a vector
    vector<int> vec1(6);
	vec1[0] = 10;
	vec1[1] = 20;
	vec1[2] = 30;
	vec1[3] = 40;
	vec1[4] = 50;
	vec1[5] = 60;

    // declare iterator i1
    vector<int>::iterator i1;
    // declare iterator i2
    vector<int>::iterator i2;
    vector<int>::iterator it_indx = vec1.begin() + 3;

	// random access
	cout << *it_indx << endl;
    // initialize i1 and point it to 
    // the first element of the vector
    i1 = vec1.begin();

    // initialize i2 and point it to 
    // the last element of the vector
    i2 = vec1.end();

    // compare i1 and i2 using the 
    // relational operator
    if (i1 < i2)
        cout << "Iterator i2 is greater than iterator i1.";
	else
        cout << "Iterator i2 is less than iterator i1.";


    // computing the distance using 
    // the arithmetic operator
    int difference = i2 - i1; 
    cout << "\nThe difference between i1 and i2 = " << difference;
    cout << "\n\n";
    return 0;
}