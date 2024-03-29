﻿//Write a function :
//
//int solution(int A, int B, int K);
//
//that, given three integers A, Band K, returns the number of integers within the range[A..B] that are divisible by K, i.e.:
//
//{ i: A ≤ i ≤ B, i mod K = 0 }
//
//For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range[6..11], namely 6, 8 and 10.
//
//Write an efficient algorithm for the following assumptions :
//
//A and B are integers within the range[0..2, 000, 000, 000];
//K is an integer within the range[1..2, 000, 000, 000];
//A ≤ B.

int solution(int A, int B, int K)
{
	if (K == 1)
	{
		return B - A + 1;
	}
	// will happen when range is [A, K]
	if (K == B)
	{
		// will happen when range is [0,K]
		if (A == 0)
			return 2;
		return 1;
	}
	if (A == B)
	{
		// [0,0], [5,5,5]
		if (A == 0 || B == 0 || A % K == 0)
			return 1;
		return 0;
	}

	int count = 0;
	count = (B / K - A / K);
	if (A % K == 0)
		++count;

	return count;
}