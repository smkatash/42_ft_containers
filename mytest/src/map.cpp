# include "base.hpp"
// # define USING_STD std

// template <typename T>
// class foo {
// 	public:
// 		typedef T	value_type;

// 		foo(void) : value(), _verbose(false) { };
// 		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
// 		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
// 		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
// 		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
// 		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
// 		foo &operator=(value_type src) { this->value = src; return *this; };
// 		foo &operator=(foo const &src) {
// 			if (this->_verbose || src._verbose)
// 				std::cout << "foo::operator=(foo) CALLED" << std::endl;
// 			this->value = src.value;
// 			return *this;
// 		};
// 		value_type	getValue(void) const { return this->value; };
// 		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

// 		operator value_type(void) const {
// 			return value_type(this->value);
// 		}
// 	private:
// 		value_type	value;
// 		bool		_verbose;
// };

// template <typename T>
// std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
// 	o << bar.getValue();
// 	return o;
// }
// // --- End of class foo

// template <typename T>
// T	inc(T it, int n)
// {
// 	while (n-- > 0)
// 		++it;
// 	return (it);
// }

// template <typename T>
// T	dec(T it, int n)
// {
// 	while (n-- > 0)
// 		--it;
// 	return (it);
// }

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T>
std::string	printPairPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value pair: " << iterator->second.first << " and " << iterator->second.second;
	if (nl)
		o << std::endl;
	return ("");
}


template <typename T1, typename T2>
static void	print_content(NAMESPACE::map<T1, T2> const &mp, bool print_content = true)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename NAMESPACE::map<T1, T2>::const_iterator itB = mp.begin(), itE = mp.end();
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

template <typename T1, typename T2>
static void	print_content_pair(NAMESPACE::map<T1, T2> const &mp, bool print_content = true)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename NAMESPACE::map<T1, T2>::const_iterator itB = mp.begin(), itE = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		if (mp.empty()) {
			std::cout << " empty" << std::endl;
		} else {
			for (; itB != itE; ++itB)
				std::cout << "- " << printPairPair(itB, false) << std::endl;
		}
	} else {
			std::cout << "this is a class" << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	}
	//std::cout << std::boolalpha << T3 << std::endl;
}

typedef NAMESPACE::pair<std::string, std::string> mypair;

void mconstructors()
{
	std::cout << "########## TEST: Constructors ############" << std::endl;
	NAMESPACE::map<char,int> first;
	print_content(first);
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;
	print_content(first);

	NAMESPACE::map<char,int> second(first.begin(),first.end());
	print_content(second);
	NAMESPACE::map<char,int> third(second);
	print_content(third);

	std::string names[10] = {"Kany", "Makany", "George", "Bush", "Trump", "Obama", "Putin", "Merkel", "42", "Paris"};
	NAMESPACE::map<int, mypair> fourth;
	for (int i = 0, j = 1; j <= 5; i++, j++) {
		fourth.insert(NAMESPACE::make_pair(j, NAMESPACE::make_pair(names[i], names[i + 1])));
		i++;
	}
	print_content_pair(fourth);

	NAMESPACE::map<int, mypair> fifth = fourth;
	print_content_pair(fifth);
}

void	miterators() {
	std::cout << "########## TEST: Iterators ############" << std::endl;
	NAMESPACE::map<int, std::string> mp;
	for (int i=1; i <= 5; i++)
		mp.insert(NAMESPACE::make_pair(i, "Hello42"));

	std::cout << "map contains: "  << std::endl;
	for (NAMESPACE::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << "key: " << it->first << " | value: " << it->second;
	std::cout << std::endl;
	std::cout << "reverse map contains: "  << std::endl;
	for (NAMESPACE::map<int, std::string>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it)
		std::cout << "key: " << it->first << " | value: " << it->second;
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;

	std::cout << "map contains: "  << std::endl;
	NAMESPACE::map<int, float> mpf;
	for (int i=1; i <= 5; i++)
	mpf.insert(NAMESPACE::make_pair(i, i * 1.2));
	for (NAMESPACE::map<int, float>::iterator it = mpf.begin(); it != mpf.end(); ++it)
		std::cout << "key: " << it->first << " | value: " << it->second;
	std::cout << std::endl;
	std::cout << "map iter begins at " << mpf.begin()->first << " - " << mpf.begin()->second << std::endl;
	std::cout << "map iter ends at " << (mpf.end()--)->first << " - " << (mpf.end()--)->second << std::endl;
	std::cout << "map iter reverse begins at " << mpf.rbegin()->first << " - " << mpf.rbegin()->second << std::endl;
	std::cout << "map iter reverse ends at " << (mpf.rend()--)->first << " - " << (mpf.rend()--)->second << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<double>	v_db;
	for (int i = 1; i <= 10; i++) {
		v_db.push_back(static_cast<double>(i * 4.24242));
	}
	std::cout << "const_iterator and const_reverse_iterator: "  << std::endl;
	NAMESPACE::map<double>::const_iterator const_it = v_db.begin();
	for (; const_it != v_db.end(); const_it++) {
		std::cout << *const_it << " ";
	}
	std::cout << std::endl;
	NAMESPACE::map<double>::const_reverse_iterator rconst_it = v_db.rbegin();
	for (; rconst_it != v_db.rend();rconst_it++) {
		std::cout << *rconst_it << " ";
	}
}

// void	map() {
// 	mconstructors();
// 	miterators();
// 	mmodifiers();
// 	maccess();
// 	mmemory();
// 	mothers();
// 	mrelational_operators();
// }