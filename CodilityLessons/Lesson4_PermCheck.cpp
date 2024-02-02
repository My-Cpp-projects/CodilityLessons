//A non - empty array A consisting of N integers is given.
//
//A permutation is a sequence containing each element from 1 to N once, and only once.
//
//For example, array A such that :
//
//A[0] = 4
//A[1] = 1
//A[2] = 3
//A[3] = 2
//is a permutation, but array A such that :
//
//A[0] = 4
//A[1] = 1
//A[2] = 3
//is not a permutation, because value 2 is missing.
//
//The goal is to check whether array A is a permutation.
//
//Write a function :
//
//int solution(vector<int> &A);
//
//that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
//
//For example, given array A such that :
//
//A[0] = 4
//A[1] = 1
//A[2] = 3
//A[3] = 2
//the function should return 1.
//
//Given array A such that :
//
//A[0] = 4
//A[1] = 1
//A[2] = 3
//the function should return 0.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[1..100, 000];
//each element of array A is an integer within the range[1..1, 000, 000, 000].

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(std::vector<int> &A)
{
	std::vector<bool> seen(A.size());

	for (auto it = A.begin(); it != A.end(); ++it)
	{
		if (*it < 0 || *it > A.size() || true == seen.at(*it - 1))
		{
			return 0;
		}
		seen.at(*it - 1) = true;
	}
	return 1;
}

int solution_2(vector<int> A)
{
	std::sort(A.begin(), A.end());
	const auto& highestValue = A.back();
	if (A.size() != highestValue)
		return false;

	std::unordered_set<int> unique;
	for (const auto& a : A)
	{
		auto insertionResult = unique.insert(a);
		if (insertionResult.second == false)
		{
			// insertion didnt take place because value exists
			return false;
		}
	}
	if (unique.size() != A.size())
		return false;

	return true;
}
