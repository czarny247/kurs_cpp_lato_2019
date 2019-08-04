#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

void runList()
{
	std::list<int> l;
	int maxValue = 1'000'000;
	std::generate_n(std::back_inserter(l), maxValue, []()
		{
			static int i = 0;
			return ++i;
		});

	/*
	time ./a.out

	real	0m0,153s
	user	0m0,149s
	sys	    0m0,004s
	*/

	auto it = l.begin();
	std::advance(it, 50'000);
	std::cout << *it << "\n";

	/*
	time ./a.out

	real	0m0,157s
	user	0m0,142s
	sys		0m0,013s
	*/
}

void runVector()
{
	std::vector<int> v;
	int maxValue = 1'000'000;
	std::generate_n(std::back_inserter(v), maxValue, []()
		{
			static int i = 0;
			return ++i;
		});

	/*
    time ./a.out

	real	0m0,042s
	user	0m0,038s
	sys		0m0,004s
	*/
	
	auto it = v.begin();
	std::advance(it, 50'000);
	std::cout << *it << "\n";

	/*
    time ./a.out

	real	0m0,044s
	user	0m0,040s
	sys	    0m0,004s
	*/
}

int main()
{
	//runList();
	runVector();
	return 0;
}
