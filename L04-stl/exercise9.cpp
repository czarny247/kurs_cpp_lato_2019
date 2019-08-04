#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

bool isPalindrome(const std::string& expression)
{	
	std::string exprWithoutPunctMark;

	std::copy_if(expression.begin(), expression.end(), 
		std::back_inserter(exprWithoutPunctMark), 
		[](const char& c){ return !ispunct(c) && !isspace(c);});

	std::transform(exprWithoutPunctMark.begin(), exprWithoutPunctMark.end(), 
		exprWithoutPunctMark.begin(),
    	[](const char& c){ return std::tolower(c); });

	auto firstEnd = exprWithoutPunctMark.begin() + exprWithoutPunctMark.length()/2;

	auto mismatchResult = std::mismatch(exprWithoutPunctMark.begin(), firstEnd,
		exprWithoutPunctMark.rbegin());

	return mismatchResult.first == firstEnd;
}

void checkPalindromes(const std::vector<std::string>& expressions)
{
	std::string resultDescription {""};
	for (const auto& expression : expressions)
	{
		resultDescription = isPalindrome(expression)
			? " is a palindrome."
			: " is not a palindrome.";
			
		
		std::cout << "The expression \"" << expression << "\"" 
			<< resultDescription << "\n";
	}
}

int main()
{
	const std::vector<std::string> expressions 
		{
			"a",
			"kajak",
			"nb",
			"Do geese see God?"
		};
	
	checkPalindromes(expressions);
	
	return 0;
}