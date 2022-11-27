#include <iostream>
#include <vector>

using namespace std;

template<class FIterator>
void forwardIterator(FIterator start, FIterator end)
{
     while(start != end)
     {
         // dereference the iterator
         // to print its value
         cout << *start << " ";
         start++;
     }
}

int main(void)
{
  // declare a vector
  vector<int> v1;

    // add elements to the vector v1
  for(int i = 1; i <= 10; i++)  
  {  
      v1.push_back(i);
  }
  // call the forward Iterator function
  // pass the vector v1
  forwardIterator(v1.begin(),v1.end());
  cout << "\n\n";
  return 0;  
}