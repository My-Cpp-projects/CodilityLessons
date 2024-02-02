//A non - empty array A consisting of N integers is given.A pair of integers(P, Q), such that 0 ≤ P < Q < N, is called a slice of array A(notice that the slice contains at least two elements).The average of a slice(P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice.To be precise, the average equals(A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
//
//    For example, array A such that :
//
//A[0] = 4
//A[1] = 2
//A[2] = 2
//A[3] = 5
//A[4] = 1
//A[5] = 5
//A[6] = 8
//contains the following example slices :
//
//slice(1, 2), whose average is(2 + 2) / 2 = 2;
//slice(3, 4), whose average is(5 + 1) / 2 = 3;
//slice(1, 4), whose average is(2 + 2 + 5 + 1) / 4 = 2.5.
//The goal is to find the starting position of a slice whose average is minimal.
//
//Write a function :
//
//int solution(vector<int> &A);
//
//that, given a non - empty array A consisting of N integers, returns the starting position of the slice with the minimal average.If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.
//
//For example, given array A such that :
//
//A[0] = 4
//A[1] = 2
//A[2] = 2
//A[3] = 5
//A[4] = 1
//A[5] = 5
//A[6] = 8
//the function should return 1, as explained above.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[2..100, 000];
//each element of array A is an integer within the range[−10, 000..10, 000].


// SOLUTION EXPLANATION
// Consider a slice of length 2, (P, Q), where Pand Q are indices in the array A.
// The average of this slice is(A[P] + A[Q]) / 2. Since the slice must contain at least two elements,
// the smallest possible length for a slice is 2. Any slice of length 1 would simply be an individual element, and the average of a single element is itself.
//
// Now, let's consider a slice of length 3, (P, Q), where P and Q are indices in the array A.
// The average of this slice is (A[P] + A[P+1] + A[Q]) / 3.
//
// When we examine slices of greater length, we are essentially taking averages of consecutive elements over longer intervals.
// However, if we think about it, for a slice of length greater than 3, we can always break it down into overlapping slices of length 2 or 3. 
// This is because any slice of length greater than 3 can be represented as a combination of slices of length 2 and 3 that overlap by one or two elements.
//
// Given this observation, we can see that any slice with the minimum average must be of length 2 or 3, as any longer slice can be decomposed into shorter slices that are of length 2 or 3.
// Therefore, we only need to consider slices of lengths 2 and 3 in our search for the minimal average slice.This insight allows us to reduce the search spaceand optimize our solution.

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A)
{
    int min_idx = 0;
    double min_avg = (A[0] + A[1]) / 2.0;

    for (int i = 0; i < A.size() - 2; ++i) 
    {
        double avg2 = (A[i] + A[i + 1]) / 2.0;
        double avg3 = (A[i] + A[i + 1] + A[i + 2]) / 3.0;

        if (avg2 < min_avg) 
        {
            min_avg = avg2;
            min_idx = i;
        }

        if (avg3 < min_avg) 
        {
            min_avg = avg3;
            min_idx = i;
        }
    }

    // Check the last 2 elements
    double avg2 = (A[A.size() - 2] + A[A.size() - 1]) / 2.0;
    if (avg2 < min_avg) 
    {
        min_idx = A.size() - 2;
    }

    return min_idx;
}