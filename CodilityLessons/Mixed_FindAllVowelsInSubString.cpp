#include <iostream>
#include <string>
#include <array>
#include <algorithm>

bool isVowel(const char c)
{
	constexpr std::array<char, 5> foo = { 'a','e','i','o','u' };
	if (std::any_of(foo.begin(), foo.end(), [&c](char foo_c) {return foo_c == c; }))
	{
		return true;
	}
	return false;
}

int countVowels(const std::string& str)
{
	int count = 0;

	for (const auto c : str)
	{
		if (isVowel(c))
		{
			++count;
		}
	}

	return count;
}

void solution(const std::string& input)
{
	int sum = 0;

	for (int i = 1; i <= input.size(); ++i)
	{
		const auto sub = input.substr(0, i);
		sum += countVowels(sub);
	}

	int amountOfSubStrings = input.size();
	int tempSum = sum;
	std::string tempSub = input;

	for (int i = 1; i < input.size(); ++i)
	{
		const auto firstChar = tempSub[0];
		tempSub = input.substr(i, input.size());
		if (isVowel(firstChar))
		{
			tempSum = tempSum - amountOfSubStrings;
		}
		--amountOfSubStrings;
		sum += tempSum;
	}

	std::cout << sum << std::endl;
}

void driver()
{
	std::string input;
	std::cout << "Enter string: " << std::endl;
	std::cin >> input;

	solution(input);
}