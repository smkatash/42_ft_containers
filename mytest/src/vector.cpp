# include "base.hpp"
// # define USING_STD std

template <typename T>
static void	print_content(NAMESPACE::vector<T> const &vct, bool print_content = true) {
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename NAMESPACE::vector<T>::const_iterator itB = vct.begin();
		typename NAMESPACE::vector<T>::const_iterator itE = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		if (vct.empty()) {
			std::cout << " empty" << std::endl;
		} else {
			for (; itB != itE; ++itB)
				std::cout << " - " << *itB << std::endl;
		}
	} else {
			std::cout << "this is a class" << std::endl;
	}
	std::cout << "<-------------------------------------->" << std::endl;
}

void	vrelational_operators() {
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	vothers() {
	NAMESPACE::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
	std::cout << "vector empty: " << std::boolalpha << myvector.empty();

	NAMESPACE::vector<std::string>	v24;
	NAMESPACE::vector<std::string>	v42;

	for (int i = 0; i <= 10; i++) {
		v42.push_back("42");
		v24.push_back("24");
	}
	std::cout << "This is 42" << std::endl;
	print_content(v42);
	std::cout << "This is 24" << std::endl;
	print_content(v24);
	std::cout << "...swap" << std::endl;
	v24.swap(v42);
	std::cout << "This is 42" << std::endl;
	print_content(v42);
	std::cout << "This is 24" << std::endl;
	print_content(v24);
}

void	vmemory() {
	NAMESPACE::vector<std::string>	vres;
	NAMESPACE::vector<std::string>	v;

	vres.reserve(10);
	NAMESPACE::vector<std::string>::iterator it = vres.begin();
	for (int i = 0; i <= 10; i++) {
		vres.push_back("42");
	}
	// TODO check the time difference
	for (int i = 0; i <= 10; i++) {
		v.push_back("42");
	}
	print_content(vres);
	print_content(v);
	std::cout << "<-------------------------------------->" << std::endl;
	vres.resize(5);
	vres.resize(8, "24");
	vres.resize(15);
	print_content(vres);
}



void	vaccess(){
	NAMESPACE::vector<int> myvector(10);

	for (unsigned i=0; i < myvector.size(); i++)
		myvector.at(i) = i + 25;
  	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
   		 std::cout << ' ' << myvector.at(i);
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::vector<std::string>	vstr(20);

	for (unsigned i = 0; i < vstr.size(); i++)
		vstr[i] = "hey";
  	std::cout << "vstr contains:";
	for (unsigned i = 0; i < vstr.size(); i++)
   		 std::cout << ' ' << vstr[i];
	std::cout << std::endl;
}

void	vmodifiers() {
	std::cout << "########## TEST: Modifiers ############" << std::endl;
	std::cout << "Assign" << std::endl;
	NAMESPACE::vector<int>				vect;
	NAMESPACE::vector<std::string>		vstr;
	NAMESPACE::vector<float>			vfl;
	NAMESPACE::vector<double>			vdb;

	vect.assign(20, 94);
	vstr.assign(21, "container");
	vfl.assign(22, 0.3);
	vdb.assign(0, 0.333333);
	print_content(vect);
	print_content(vstr);
	print_content(vfl);
	print_content(vdb);
	std::cout << "Assign range" << std::endl;
	vect.assign(vect.begin() + 5, vect.end() - 1);
	vstr.assign(vstr.rbegin() + 2, vstr.rend() - 1);
	vfl.assign(vfl.begin(), vfl.end() - 5);
	print_content(vect);
	print_content(vstr);
	print_content(vfl);
	std::cout << "<-------------------------------------->" << std::endl;
	std::cout << "Pop & push" << std::endl;
	vect.pop_back();
	vstr.pop_back();
	vfl.pop_back();
	print_content(vect);
	print_content(vstr);
	print_content(vfl);
	vect.push_back(5);
	vstr.push_back("hello");
	vfl.push_back(2.33);
	std::cout << "<-------------------------------------->" << std::endl;
	std::cout << "Erase, empty & clear" << std::endl;
	vect.erase(vect.begin(), vect.begin() + 2);
	vstr.erase(vstr.begin(), vstr.begin() + 3);
	vfl.erase(vfl.begin(), vfl.begin() + 4);
	print_content(vect);
	print_content(vstr);
	print_content(vfl);
	std::cout << "<-------------------------------------->" << std::endl;
	std::cout << "vector<int> empty: " << std::boolalpha << vect.empty() << std::endl;
	std::cout << "vector<std::string> empty: " << std::boolalpha << vstr.empty() << std::endl; 
	std::cout << "vector<float> empty: " << std::boolalpha <<  vfl.empty() << std::endl;
	vect.clear();
	vstr.clear();
	vfl.clear();
	print_content(vect);
	print_content(vstr);
	print_content(vfl);
	std::cout << "vector<int> empty: " << std::boolalpha << vect.empty() << std::endl;
	std::cout << "vector<std::string> empty: " << std::boolalpha << vstr.empty() << std::endl; 
	std::cout << "vector<float> empty: " << std::boolalpha <<  vfl.empty() << std::endl;

}

void	viterators() {
	std::cout << "########## TEST: Iterators ############" << std::endl;
	NAMESPACE::vector<int> vect;
	for (int i=1; i <= 5; i++)
		vect.push_back(i * 2);

	std::cout << "vector contains: "  << std::endl;
	for (NAMESPACE::vector<int>::iterator it = vect.begin() ; it != vect.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "reverse vector contains: "  << std::endl;
	for (NAMESPACE::vector<int>::reverse_iterator it = vect.rbegin() ; it != vect.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	std::string str = ". Ich bin Kanykei.";
	std::string num;
	NAMESPACE::vector<std::string> vstr;
	for (int i = 1; i <= 5; i++) {
		num = std::to_string(i) + str;
		vstr.push_back(num);
	}
	std::cout << "vector contains: "  << std::endl;
	for (NAMESPACE::vector<std::string>::iterator it = vstr.begin() ; it != vstr.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "vector front is " << vstr.front() << std::endl;
	std::cout << "vector back is " << vstr.back() << std::endl;
	std::cout << "vector iter begins at " << *(vstr.begin()) << std::endl;
	std::cout << "vector iter ends at " << *(vstr.end() - 1) << std::endl;
	std::cout << "vector iter reverse begins at " << *(vstr.rbegin()) << std::endl;
	std::cout << "vector iter reverse ends at " << *(vstr.rend() - 1) << std::endl;
	std::cout << "<-------------------------------------->" << std::endl;
	NAMESPACE::vector<double>	v_db;
	for (int i = 1; i <= 10; i++) {
		v_db.push_back(static_cast<double>(i * 4.24242));
	}
	std::cout << "const_iterator and const_reverse_iterator: "  << std::endl;
	NAMESPACE::vector<double>::const_iterator const_it = v_db.begin();
	for (; const_it != v_db.end(); const_it++) {
		std::cout << *const_it << " ";
	}
	std::cout << std::endl;
	NAMESPACE::vector<double>::const_reverse_iterator rconst_it = v_db.rbegin();
	for (; rconst_it != v_db.rend();rconst_it++) {
		std::cout << *rconst_it << " ";
	}
}

void	vconstructors() {
	std::cout << "########## TEST: Constructors ############" << std::endl;
	std::cout << "default constructor" << std::endl;
	NAMESPACE::vector<int>						v_int;
	NAMESPACE::vector<std::string>				v_string;
	NAMESPACE::vector<bool>						v_bool;
	NAMESPACE::vector<double>					v_double;
	NAMESPACE::vector<float>					v_float;
	NAMESPACE::vector<TestClass<int> >			v_intClass;
	NAMESPACE::vector<TestClass<std::string> >	v_stringClass;
	print_content(v_int);
	print_content(v_string);
	print_content(v_bool);
	print_content(v_double);
	print_content(v_float);
	print_content(v_intClass, false);
	print_content(v_stringClass, false);

	std::cout << "fill constructor" << std::endl;
	NAMESPACE::vector<int>						v_int_fill(5, 42);
	NAMESPACE::vector<int>						v_int_fill2(0, 42);
	NAMESPACE::vector<std::string>				v_string_fill(5, "Hello");
	// AS in STD:: exception
	// NAMESPACE::vector<std::string>				v_string_fill2(-1, "Hello");
	// AS in STD::segfault !!!
	// NAMESPACE::vector<std::string>				v_string_fill2(0, "Hello");
	NAMESPACE::vector<std::string>				v_string_fill2(12, "world");
	NAMESPACE::vector<bool>						v_bool_fill(5, false);
	NAMESPACE::vector<double>					v_double_fill(5, 42.4242);
	NAMESPACE::vector<float>					v_float_fill(42, 1.2);
	NAMESPACE::vector<TestClass<int> >			v_intClass_fill(5, TestClass<int>(25));
	NAMESPACE::vector<TestClass<std::string> >	v_stringClass_fill(5, TestClass<std::string>("lalala"));
	print_content(v_int_fill);
	print_content(v_int_fill2);
	print_content(v_string_fill);
	print_content(v_string_fill2);
	print_content(v_bool_fill);
	print_content(v_double_fill);
	print_content(v_float_fill);
	print_content(v_intClass_fill, false);
	print_content(v_stringClass_fill, false);
	std::cout << "range constructor" << std::endl;
	NAMESPACE::vector<int>						v_int_range(v_int_fill.begin(), v_int_fill.end());
	NAMESPACE::vector<int>						v_int_range2(v_int_fill2.begin(), v_int_fill2.end());
	NAMESPACE::vector<std::string>				v_string_range(v_string_fill.begin() + 2,v_string_fill.end());
	NAMESPACE::vector<std::string>				v_string_range2(v_string_fill2.begin(), v_string_fill2.end());
	NAMESPACE::vector<bool>						v_bool_range(v_bool_fill.begin(), v_bool_fill.end() - 2);
	NAMESPACE::vector<double>					v_double_range(v_double_fill.begin(), v_double_fill.end());
	NAMESPACE::vector<float>					v_float_range(v_float_fill.begin() + 10, v_float_fill.end() - 2);
	NAMESPACE::vector<TestClass<int> >			v_intClass_range(v_intClass_fill.begin(), v_intClass_fill.begin() + 1);
	NAMESPACE::vector<TestClass<std::string> >	v_stringClass_range(v_stringClass_fill.end() - 3, v_stringClass_fill.end());
	print_content(v_int_range);
	print_content(v_int_range2);
	print_content(v_string_range);
	print_content(v_string_range2);
	print_content(v_bool_range);
	print_content(v_double_range);
	print_content(v_float_range);
	print_content(v_intClass_range, false);
	print_content(v_stringClass_range, false);
	std::cout << "copy constructor" << std::endl;
	NAMESPACE::vector<int>						v_int_copy(v_int_range);
	NAMESPACE::vector<int>						v_int_copy2(v_int_range2);
	NAMESPACE::vector<std::string>				v_string_copy(v_string_range);
	NAMESPACE::vector<std::string>				v_string_copy2(v_string_range2);
	NAMESPACE::vector<bool>						v_bool_copy(v_bool_range);
	NAMESPACE::vector<double>					v_double_copy(v_double_range);
	NAMESPACE::vector<float>					v_float_copy(v_float_range);
	NAMESPACE::vector<TestClass<int> >			v_intClass_copy(v_intClass_fill);
	NAMESPACE::vector<TestClass<std::string> >	v_stringClass_copy(v_stringClass_fill);
	print_content(v_int_copy);
	print_content(v_int_copy2);
	print_content(v_string_copy);
	print_content(v_string_copy2);
	print_content(v_bool_copy);
	print_content(v_double_copy);
	print_content(v_float_copy);
	print_content(v_intClass_copy, false);
	print_content(v_stringClass_copy, false);


	std::cout << "Assignment operator" << std::endl;
	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	NAMESPACE::vector<int> v_input_int (myints, myints + sizeof(myints) / sizeof(int) );
	NAMESPACE::vector<int> new_int = v_input_int;
	std::string mystrings[] = {"snow", "rain", "sun", "fog"};
	NAMESPACE::vector<std::string> v_input_string (mystrings, mystrings + 4);
	NAMESPACE::vector<std::string> new_string = v_input_string;
	print_content(v_input_int);
	print_content(new_int);
	print_content(v_input_string);
	print_content(new_string);
};