# include <map>
# include <iostream>
using namespace std;


	bool fncomp (char lhs, char rhs) {return lhs<rhs;}

	struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
	};

void	insertion() {

	map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert (pair<char,int>('a',100) );
	mymap.insert (pair<char,int>('z',200) );

	pair<map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

	std::cout << "done" << std::endl;
	map<char,int>::iterator it2 = mymap.begin();
	for (; it2 != mymap.end(); it2++) {
		std::cout << (*it2).first << " ";
		std::cout << (*it2).second << std::endl;
	}
}


int main ()
{
	insertion();
	// map<char,int> first;

	// first['a']=10;
	// first['b']=30;
	// first['c']=50;
	// first['d']=70;

	// map<char, int>::iterator it = first.begin();
	// for (; it != first.end(); it++) {
	// 	std::cout << (*it).first << " " << (*it).second << std::endl;
	// }

	// map<char,int> second (first.begin(),first.end());

	// map<char,int> third (second);

	// map<char,int,classcomp> fourth;                 // class as Compare

	// bool(*fn_pt)(char,char) = fncomp;
	// map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	return 0;
}