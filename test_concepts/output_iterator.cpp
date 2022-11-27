#include <iostream>
#include <vector>

using namespace std;

int main (void) 
{
	// initialize 2 vectors
   vector<int> v1, v2;
   // add elements into the vectors
   for (int i = 1; i <= 10; i++) { 
	  v1.push_back(i);
	  v2.push_back(i + 2);
   }

   // initialize an iterator itr pointing to 
   // the first element in vector v1 
   vector<int>::iterator itr = v1.begin(); 
   vector<int>::iterator itr_out = itr;
	cout << "Initial index: " << *itr << endl;
	// copy elements of v2 vector to v1 vector at 
	// the beginning
	copy(v2.begin(), v2.end(), inserter(v1, itr));
   // print the elements of the vector v1

   cout<<"Elements of vector v1 after copying elements of v2 are :"<< endl;
   for ( itr = v1.begin(); itr!= v1.end(); ++itr ) 
   {
	  cout << " " << *itr;
   }
	  cout << "\n";
	cout << "Initial index overloaded into new iter: " << *itr_out << endl;
	cout << "Output: " << *itr_out << " " << *itr << endl;
	return 0;
}