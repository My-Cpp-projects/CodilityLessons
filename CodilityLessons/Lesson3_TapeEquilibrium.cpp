



#include <vector>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;

int solution(vector<int> &A)
{
	int firstPart = A[0];
	int secondPart = accumulate(A.begin() + 1, A.end(), 0);
	int minDif = INT_MAX;

	for (int i = 1; i < A.size(); ++i)
	{
		int currentDif = abs(firstPart - secondPart);
		minDif = min(minDif, currentDif);
		firstPart += A[i];
		secondPart -= A[i];
	}

	return minDif;
}

int solution_2(vector<int>& A)
{
	int minDiff = INT_MAX;
	vector<int> prefixSums(A.size());
	prefixSums[0] = A[0];

	for (int i = 1; i < A.size(); ++i)
	{
		prefixSums[i] = prefixSums[i - 1] + A[i];
	}

	for (int p = 1; p < prefixSums.size(); ++p)
	{
		int leftSum = prefixSums[p - 1];
		int rightSum = prefixSums[prefixSums.size() - 1] - prefixSums[p - 1];
		minDiff = min(minDiff, abs(rightSum - leftSum));
	}

	return minDiff;
}