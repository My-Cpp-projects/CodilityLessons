//An array A consisting of N different integers is given.The array contains integers in the range[1..(N + 1)], which means that exactly one element is missing.
//
//Your goal is to find that missing element.
//
//Write a function :
//
//int solution(vector<int> &A);
//
//that, given an array A, returns the value of the missing element.
//
//For example, given array A such that :
//
//A[0] = 2
//A[1] = 3
//A[2] = 1
//A[3] = 5
//the function should return 4, as it is the missing element.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[0..100, 000];
//the elements of A are all distinct;
//each element of array A is an integer within the range[1..(N + 1)].

#include <vector>
#include <numeric>

int solution(std::vector<int>& A)
{
	unsigned long actualSum = std::accumulate(A.begin(), A.end(), 0);
	unsigned long biggestElement = A.size() + 1;
	unsigned long& numberOfElements = biggestElement;
	unsigned long trueSum = (numberOfElements * (1 + biggestElement)) / 2;
	return trueSum - actualSum;
}

int solution_2(std::vector<int> &A)
{
	if (A.empty())
	{
		return 1;
	}

	unsigned long long largestNumber = A.size() + 1;
	unsigned long long realSum = (largestNumber * (1 + largestNumber)) / 2;

	unsigned long long ourSum = 0;

	for (auto it = A.begin(); it != A.end(); ++it)
	{
		ourSum += *it;
	}
	return realSum - ourSum;
}
