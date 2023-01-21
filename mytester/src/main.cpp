# include "base.hpp"

void	stack() {
	sconstructors();
	smodifiers();
	srelational_operators();
}

void	map() {
	mconstructors();
	miterators();
	maccess();
	mmemory();
	mothers();
	mrelational_operators();
}

void	vector() {
	vconstructors();
	viterators();
	vmodifiers();
	vaccess();
	vmemory();
	vothers();
	vrelational_operators();
}

void	checkleaks()
{
	system("leaks tester");
}

int main() {
	struct timeval start, end;
	long seconds;
	long microseconds;

	//atexit(checkleaks);
	std::cout << "!!!!!!!!!            START OF VECTOR TEST            !!!!!!!" << std::endl << std::endl;
	gettimeofday(&start, NULL);
	vector();
	gettimeofday(&end, NULL);
	std::cout << "!!!!!!!!!            END OF VECTOR TEST              !!!!!!!!" << std::endl << std::endl;
	seconds = (end.tv_sec - start.tv_sec);
	microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	std::cout << std::endl << "VECTOR took: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds" << std::endl;
	std::cout << std::endl;
	std::cout << "!!!!!!!!!            START OF MAP TEST               !!!!!!!" << std::endl << std::endl;
	gettimeofday(&start, NULL);
	map();
	gettimeofday(&end, NULL);
	std::cout << "!!!!!!!!!            END OF MAP TEST                 !!!!!!!" << std::endl << std::endl;
	seconds = (end.tv_sec - start.tv_sec);
	microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	std::cout << std::endl << "MAP took: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds" << std::endl;
	std::cout << std::endl;
	std::cout << "!!!!!!!!!            START OF STACK TEST             !!!!!!!" << std::endl << std::endl;
	gettimeofday(&start, NULL);
	stack();
	gettimeofday(&end, NULL);
	std::cout << "!!!!!!!!!            END OF STACK TEST               !!!!!!!" << std::endl << std::endl;
	seconds = (end.tv_sec - start.tv_sec);
	microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	std::cout << std::endl << "STACK took: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds" << std::endl;
	std::cout << std::endl;
	return 0;
}