# include "../../include/map.hpp"

# include <iostream>
# include <cstdlib>
#include <cstddef>
#include <functional>
#include <map>

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

void init_array_int_str(pair<int, std::string>* arr, std::size_t size)
{
	std::string x[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
						  "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
						  "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
						  "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
						  "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
						  "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
						  "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
						  "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
						  "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
						  "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
						  "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
						  "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
						  "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
						  "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
						  "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
						  "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
						  "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
						  "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
						  "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
						  "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
						  "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
						  "1IRLC9sfQI5AzDYeotLd" };
	int y;
	for (std::size_t i = 0; i < size; ++i) {
		y = rand();
		arr[i] = ft::make_pair(y, x[i]);
	}
}

void	comparisons() {
	map<int, std::string> a;
	map<int, std::string> b;

	if (a == b)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	pair<int, std::string> arr[64];
	init_array_int_str(arr, 64);
	map<int, std::string> c(arr, arr + 1);
	map<int, std::string> d;
	if (c == d)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	map<int, std::string> e(arr, arr + 1);
	map<int, std::string> f(arr, arr + 1);
	if (e == f)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	map<int, std::string> g(arr, arr + 5);
	map<int, std::string> h;
	h.insert(make_pair(5, "Hello"));
	h.insert(make_pair(7, "Hello"));
	h.insert(make_pair(8, "Hello"));
	h.insert(make_pair(1, "Hello"));
	h.insert(make_pair(0, "Hello"));
	if (g == h)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	map<int, std::string> l(arr, arr + 5);
	map<int, std::string> m(arr, arr + 4);
	m.insert(make_pair(5, "Hello"));
	if (l == m)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	map<int, std::string> x(arr, arr + 64);
	map<int, std::string> y(arr, arr + 64);
	if (x == y)
		std::cout << "Equal" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;
}


int main ()
{
	//insertion();
	//std::cout << std::endl << " ------------------ " << std::endl;
	//construct();
	//std::cout << std::endl << " ------------------ " << std::endl;
	//access();
	// std::cout << std::endl << " ------------------ " << std::endl;
	// deletion();
	comparisons();
	return 0;
}