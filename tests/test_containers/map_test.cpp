# include "../include/map.hpp"
# include <iostream>
using namespace ft;


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


	std::cout << "mymap contains:\n";
	// third insert function version (range insertion):
	map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}


void construct() {
	map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::cout << first['a'] << " ";
	std::cout << first['b'] << " ";
	std::cout << first['c'] << " ";
	std::cout << first['d'] << " ";

	map<char, int>::iterator it = first.begin();
	for (; it != first.end(); it++) {
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}

	map<char,int> second (first.begin(),first.end());

	map<char,int> third (second);

	map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}

void access() {
	map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void deletion(){
	map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	//insertion();
	//std::cout << std::endl << " ------------------ " << std::endl;
	//construct();
	//std::cout << std::endl << " ------------------ " << std::endl;
	//access();
	std::cout << std::endl << " ------------------ " << std::endl;
	deletion();
	return 0;
}