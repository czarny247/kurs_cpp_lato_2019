#include <forward_list>
#include <iostream>
#include <iterator>

int main()
{
	std::forward_list<int> fl {1,2,3,4,5,6,7};

	auto begin = std::begin(fl);
	auto end = std::end(fl);

	std::cout << "size: "  << std::distance(begin, end) << "\n";

	auto fifthIt = std::begin(fl);
	std::advance(fifthIt, 4);

	std::cout << "5th element: " << *fifthIt << "\n";

	std::cout << "distance(begin, fifthIt): " << std::distance(begin, fifthIt) << "\n";

	return 0;
}