#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // initialize a vector
   vector<int> v1(6);
   v1[0] = 10;
   v1[1] = 20;
   v1[2] = 30;
   v1[3] = 40;
   v1[4] = 50;
   v1[5] = 60;

    // initialize an iterator i1
   vector<int> ::iterator i1;

    // initialize a reverse iterator rITr
   vector<int> :: reverse_iterator rItr;

   // dereference and print i1 
   // to print values in original order
   cout << "Values in original order: " << "\n";
   for(i1 = v1.begin(); i1 != v1.end(); i1++)  
   {  
       cout << *i1 << " ";  
   }  
   cout << "\n\n";

   cout << "Decrement iterators: " << "\n";
   for(i1 = v1.end() - 1; i1 >= v1.begin(); i1--)  
   {  
       cout << *i1 << " ";  
   }  
   cout << "\n\n";  

   // dereference and print rItr 
   // to print values in reverse order
   cout << "Values in reverse order: " << "\n";
   for(rItr = v1.rbegin(); rItr != v1.rend(); rItr++)  
   {
       cout << *rItr << " ";
   }
   cout << "\n\n";
    return 0;
} 