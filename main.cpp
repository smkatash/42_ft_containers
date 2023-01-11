#include "./include/map.hpp"
#include <map>


int main(void) {
	ft::map<int, std::string> myMap;
	std::map<int, std::string> originalMAP;

	myMap.insert(ft::pair<int, std::string>(1, "hello"));
	originalMAP.insert(std::pair<int, std::string>(1, "hello"));
	std::cout << myMap[1] << std::endl;
	std::cout << originalMAP[1] << std::endl;
}