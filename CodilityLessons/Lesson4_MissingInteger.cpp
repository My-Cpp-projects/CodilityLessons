//This is a demo task.
//
//Write a function :
//
//int solution(vector<int>& A);
//
//that, given an array A of N integers, returns the smallest positive integer(greater than 0) that does not occur in A.
//
//For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
//
//Given A = [1, 2, 3], the function should return 4.
//
//Given A = [−1, −3], the function should return 1.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[1..100, 000];
//each element of array A is an integer within the range[−1, 000, 000..1, 000, 000].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A)
{
	// if single element
	if (A.size() == 1)
	{
		if (A.back() <= 0 || A.back() != 1)
			return 1;
		else
			return 2;
	}

	std::sort(A.begin(), A.end());

	// if all negative
	if (A.back() <= 0)
		return 1;

	// if all positive and first element is not 1
	if (A.front() > 1)
		return 1;

	// all other cases
	for (int i = 1; i < A.size(); ++i)
	{
		if (A[i - 1] < 0 && A[i] > 0 && A[i] != 1)
			return 1;

		if (A[i - 1] > 0 && A[i] > 0 && A[i] - A[i - 1] > 1)
			return A[i - 1] + 1;
	}

	// if the entire sequence was consequative positive integers starting from 1...
	return A.back() + 1;
}