# include "base.hpp"

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
	std::cout << std::endl;
	std::cout << "reverse map contains: "  << std::endl;
	for (NAMESPACE::map<int, std::string>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it)
		std::cout << "key: " << it->first << " | value: " << it->second << " , ";
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;

	std::cout << "map contains: "  << std::endl;
	NAMESPACE::map<int, float> mpf;
	for (int i=1; i <= 5; i++)
	mpf.insert(NAMESPACE::make_pair(i, i * 1.2));
	for (NAMESPACE::map<int, float>::iterator it = mpf.begin(); it != mpf.end(); ++it)
		std::cout << "key: " << it->first << " | value: " << it->second << " , ";
	std::cout << std::endl;
	std::cout << "map iter begins at " << mpf.begin()->first << " - " << mpf.begin()->second << std::endl;
	std::cout << "map iter ends at " << (--mpf.end())->first << " - " << (--mpf.end())->second << std::endl;
	std::cout << "map iter reverse begins at " << mpf.rbegin()->first << " - " << mpf.rbegin()->second << std::endl;
	std::cout << "map iter reverse ends at " << (--mpf.rend())->first << " - " << (--mpf.rend())->second << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<double, std::string> mpd;
	for (int i = 1; i <= 10; i++) {
		mpd[i * 4.24242] = "wingardium leviosa";
	}
	std::cout << "const_iterator and const_reverse_iterator: "  << std::endl;
	NAMESPACE::map<double, std::string>::const_iterator const_it = mpd.begin();
	for (; const_it != mpd.end(); const_it++) {
		std::cout << const_it->first << " - " << const_it->second << "; ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	NAMESPACE::map<double, std::string>::const_reverse_iterator revconst_it = mpd.rbegin();
	for (; revconst_it != mpd.rend(); revconst_it++) {
		std::cout << revconst_it->first << " - " << revconst_it->second << "; ";
	}
	std::cout << std::endl;
	std::cout << "range_equality: "  << std::endl;
	NAMESPACE::map<char,int> mprange;
	mprange['a'] = 10;
	mprange['b'] = 20;
	mprange['c'] = 30;
	mprange['d'] = 40;
	mprange['e'] = 50;
	mprange['f'] = 60;
	mprange['g'] = 70;

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
	ret = mprange.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "..." << std::endl;
	ret = mprange.equal_range('e');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "..." << std::endl;
	ret = mprange.equal_range('g');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	// garbage memory
	//std::cout << ret.second->first << " => " << ret.second->second << '\n';
}


void	mothers() {
	std::string names[10] = {"Hallo", "Hello", "Bonjour", "Privet", "Salam", "Ciao", "Hola", "Salve", "Konnichiwa", "Anyoung haseyo"};
	NAMESPACE::map<int, mypair> fourth;
	for (int i = 0, j = 1; j <= 5; i++, j++) {
		fourth.insert(NAMESPACE::make_pair(j, NAMESPACE::make_pair(names[i], names[i + 1])));
		i++;
	}
	print_content_pair(fourth);
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::pair<NAMESPACE::map<int, mypair>::iterator, NAMESPACE::map<int, mypair>::iterator> itlow, itup;
	std::cout << "lower bound points to: ";
	std::cout << fourth.lower_bound(1)->first << " => " << fourth.lower_bound(1)->second.first <<  " & " << fourth.lower_bound(1)->second.second <<'\n';
	std::cout << "upper bound points to: ";
	std::cout << fourth.upper_bound(4)->first << " => " << fourth.upper_bound(4)->second.first <<  " & " << fourth.upper_bound(4)->second.second <<'\n';
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<int, char> fifth;
	for (int i = 1, c = 97; c <= 122; i++, c++)
		fifth.insert(NAMESPACE::make_pair<int, char>(i, c));
	NAMESPACE::map<int, char>::iterator it = fifth.begin();
	for (; it != fifth.end(); it++) {
		std::cout << it->first << ") " << it->second << "  ";
	}
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<int, char>::iterator itcnt = fifth.begin();
	NAMESPACE::map<int, char>::iterator cnt = fifth.begin();
	for (int i = 1; i < 10; ++i)
		++cnt;
	do {
		std::cout<< itcnt->first << " = " << itcnt->second << std::endl;
	} while (fifth.value_comp()(*itcnt++, *cnt));
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	for (int i = 1; i < 10; ++i)
		++cnt;
	NAMESPACE::map<int, char>::key_compare mycomp = fifth.key_comp();
	char tenth = cnt->first;
	NAMESPACE::map<int, char>::iterator knt = fifth.begin();
	do {
		std::cout << knt->first << " => " << knt->second << '\n';
	} while ( mycomp((*knt++).first, tenth) );
}

void maccess() {
	std::cout << "########## TEST: Access ############" << std::endl;
	std::string names[10] = {"Hallo", "Hello", "Bonjour", "Privet", "Salam", "Ciao", "Hola", "Salve", "Konnichiwa", "Anyoung haseyo"};
	NAMESPACE::map<mypair, int> mp;
	for (int i = 0, j = 1; j <= 5; i++, j++) {
		mp.insert(NAMESPACE::make_pair(NAMESPACE::make_pair(names[i], names[i + 1]), j));
		i++;
	}
	NAMESPACE::map<mypair, int>::iterator it = mp.find(NAMESPACE::make_pair("Hola", "Salve"));
	std::cout << "Found: " << it->first.first << " : " << it->first.second << std::endl;
	while (++it != mp.end()) {
		std::cout << it->first.first << " : " << it->first.second << " -> " << it->second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<char,std::string> mpa;
	mpa['a']= "an element";
	mpa['b']= "another element";
	mpa['c']= mpa['b'];

	std::cout << "mpa['a'] is " << mpa['a'] << '\n';
	std::cout << "mpa['b'] is " << mpa['b'] << '\n';
	std::cout << "mpa['c'] is " << mpa['c'] << '\n';
	std::cout << "mpa now contains " << mpa.size() << " elements" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<char,std::string> mpb;
	mpb['d']= "a suprise";
	mpb['e']= "a present";
	mpb['f']= "nothing";
	mpb['g']= mpb['e'];

	std::cout << "mpb['d'] is " << mpb['d'] << '\n';
	std::cout << "mpb['e'] is " << mpb['e'] << '\n';
	std::cout << "mpb['f'] is " << mpb['f'] << '\n';
	std::cout << "mpb['g'] is " << mpb['g'] << '\n';
	std::cout << "mpb now contains " << mpb.size() << " elements" << std::endl;
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;

	NAMESPACE::map<char,std::string>::iterator itsw = mpa.begin();
	std::cout << "This is A:" << std::endl;
	for (; itsw != mpa.end(); itsw ++) {
		std::cout << itsw->first << "->" << itsw->second << " || " ;
	}
	std::cout << std::endl;
	std::cout << "This is B:" << std::endl;
	itsw = mpb.begin();
	for (; itsw != mpb.end(); itsw ++) {
		std::cout << itsw->first << "->" << itsw->second << " || " ;
	}

	std::cout << std::endl << "SWAP:" << std::endl;
	mpa.swap(mpb);
	itsw = mpa.begin();
	std::cout << "This is A:" << std::endl;
	for (; itsw != mpa.end(); itsw ++) {
		std::cout << itsw->first << "->" << itsw->second << " || " ;
	}
	std::cout << std::endl;
	std::cout << "This is B:" << std::endl;
	itsw = mpb.begin();
	for (; itsw != mpb.end(); itsw ++) {
		std::cout << itsw->first << "->" << itsw->second << " || " ;
	}
}

void	mmemory() {
	int psize;
	NAMESPACE::map<char,int> first;
	NAMESPACE::pair<const char,int>* p;

	p = first.get_allocator().allocate(5);
	psize = sizeof(NAMESPACE::map<char,int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";
	first.get_allocator().deallocate( p, 5);
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::map<char, int> second;
	for (int i = 1, c = 97; c <= 122; i++, c++) {
		second[c] = i;
	}
	print_content(second);
	NAMESPACE::map<char, int>::iterator todel = second.find('b');
	// second.erase(todel, second.end());
	// print_content(second);
	second.erase('a');
	second.erase(todel);
	print_content(second);
	// its = second.find('a');
	// second.erase(its);
	// print_content(second);
	// TODO
	// NAMESPACE::map<char, int>::iterator alldel = second.begin();
	// NAMESPACE::map<char, int>::iterator endell = second.end();
	// print_content(second);
	// for (; alldel != endell; ++alldel)
	// 	second.erase(alldel);
	std::cout << "Empty : " << std::boolalpha << second.empty() << std::endl;
	second.clear();
	std::cout << "Empty : " << std::boolalpha << second.empty() << std::endl;
}

void	mrelational_operators() {
	NAMESPACE::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}