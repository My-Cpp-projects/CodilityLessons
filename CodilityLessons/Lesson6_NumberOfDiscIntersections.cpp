//We draw N discs on a plane.The discs are numbered from 0 to N − 1. An array A of N non - negative integers, specifying the radiuses of the discs, is given.The J - th disc is drawn with its center at(J, 0) and radius A[J].
//
//We say that the J - th disc and K - th disc intersect if J ≠ Kand the J - th and K - th discs have at least one common point(assuming that the discs contain their borders).
//
//The figure below shows discs drawn for N = 6 and A as follows :
//
//A[0] = 1
//A[1] = 5
//A[2] = 2
//A[3] = 1
//A[4] = 4
//A[5] = 0
//
//
//There are eleven(unordered) pairs of discs that intersect, namely:
//
//discs 1 and 4 intersect, and both intersect with all the other discs;
//disc 2 also intersects with discs 0 and 3.
//Write a function :
//
//int solution(vector<int> &A);
//
//that, given an array A describing N discs as explained above, returns the number of(unordered) pairs of intersecting discs.The function should return −1 if the number of intersecting pairs exceeds 10, 000, 000.
//
//Given array A shown above, the function should return 11, as explained above.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[0..100, 000];
//each element of array A is an integer within the range[0..2, 147, 483, 647].

#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// 93%, overflow errors when radius is INT_MAX
int solution(std::vector<int>& A)
{
    int N = A.size();
    vector<int> start(N, 0); // Stores the start points of discs
    vector<int> end(N, 0);   // Stores the end points of discs

    // Store the start and end points of discs
    for (int i = 0; i < N; ++i)
    {
        start[max(0, i - A[i])]++;
        end[min(N - 1, i + A[i])]++;
    }

    int activeDiscs = 0; // Number of active discs at each point
    long long intersectPairs = 0; // Total number of intersecting pairs

    // Iterate through the points on the x-axis
    for (int i = 0; i < N; ++i)
    {
        intersectPairs += activeDiscs * start[i]; // Count intersecting pairs
        intersectPairs += (start[i] * (start[i] - 1)) / 2; // Count pairs within the same disc
        if (intersectPairs > 10000000)
        {
            // Check if the number of intersecting pairs exceeds the limit
            return -1;
        }
        activeDiscs += start[i] - end[i]; // Update the number of active discs
    }

    return intersectPairs;
}