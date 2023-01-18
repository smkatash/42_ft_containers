// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main (void) {
	std::pair <std::string,double> product1;                     // default constructor
	std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	std::pair <std::string,double> product3 (product2);          // copy constructor
	product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	std::cout << std::endl;
	std::pair <int,std::string> player1;
	std::pair <int,std::string> player2(2, "Tim");
	std::pair <int,std::string> player3(player2);
	player1 = std::make_pair(1, "Dim");
	player2.first = 3;
	player2.second = "Alex";
	std::cout << "Rank " << player1.first << ", player " << player1.second << std::endl;
	std::cout << "Rank " << player2.first << ", player " << player2.second << std::endl;
	std::cout << "Rank " << player3.first << ", player " << player3.second << std::endl;
	
	return 0;
}