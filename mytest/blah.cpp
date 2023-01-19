#include <iostream>
#include <map>
#include <utility>
using namespace std;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T1, typename T2>
static void	print_content(map<T1, T2> const &mp, bool print_content = true)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename map<T1, T2>::const_iterator itB = mp.begin(), itE = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		if (mp.empty()) {
			std::cout << " empty" << std::endl;
		} else {
			for (; itB != itE; ++itB)
				std::cout << "- " << printPair(itB, false) << std::endl;
		}
	} else {
			std::cout << "this is a class" << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	}
}


int main() {
	std::cout << "<-------------------------------------->" << std::endl;
	map<char, int> second;
	for (int i = 1, c = 97; c <= 122; i++, c++) {
		second[c] = i;
	}
	print_content(second);
	map<char, int>::iterator todel = second.find('k');
	second.erase(todel, second.end());
	print_content(second);
	second.erase('a');
	print_content(second);

}
