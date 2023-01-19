#include <iostream>
#include <map>
#include <utility>
using namespace std;

typedef std::pair<std::string, std::string> mypair;

int main() {
	std::map<char,int> first;
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char,int> second(first.begin(),first.end());
	std::map<char,int> third(second);

	std::string names[10] = {"Kany", "Makany", "George", "Bush", "Trump", "Obama", "Putin", "Merkel", "42", "Paris"};
	std::map<int, mypair> fourth;
	for (int i = 0; i < 5; i++) {
		fourth.insert(std::make_pair(i + 1, std::make_pair(names[i], names[i + 1])));
	}

}
