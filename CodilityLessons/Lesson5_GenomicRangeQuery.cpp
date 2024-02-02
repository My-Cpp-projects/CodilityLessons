//A DNA sequence can be represented as a string consisting of the letters A, C, Gand T, which correspond to the types of successive nucleotides in the sequence.Each nucleotide has an impact factor, which is an integer.Nucleotides of types A, C, Gand T have impact factors of 1, 2, 3 and 4, respectively.You are going to answer several queries of the form : What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence ?
//
//The DNA sequence is given as a non - empty string S = S[0]S[1]...S[N - 1] consisting of N characters.There are M queries, which are given in non - empty arrays P and Q, each consisting of M integers.The K - th query(0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K](inclusive).
//
//    For example, consider string S = CAGCCTA and arrays P, Q such that :
//
//P[0] = 2    Q[0] = 4
//P[1] = 5    Q[1] = 5
//P[2] = 0    Q[2] = 6
//The answers to these M = 3 queries are as follows :
//
//The part of the DNA between positions 2 and 4 contains nucleotides G and C(twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
//The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
//The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
//Write a function :
//
//vector<int> solution(string & S, vector<int> &P, vector<int> &Q);
//
//that, given a non - empty string S consisting of N characters and two non - empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.
//
//Result array should be returned as a vector of integers.
//
//For example, given the string S = CAGCCTA and arrays P, Q such that :
//
//P[0] = 2    Q[0] = 4
//P[1] = 5    Q[1] = 5
//P[2] = 0    Q[2] = 6
//the function should return the values[2, 4, 1], as explained above.
//
//Write an efficient algorithm for the following assumptions :
//
//N is an integer within the range[1..100, 000];
//M is an integer within the range[1..50, 000];
//each element of arrays Pand Q is an integer within the range[0..N - 1];
//P[K] ≤ Q[K], where 0 ≤ K < M;
//string S consists only of upper - case English letters A, C, G, T.

// In the preprocessing step, we calculate prefix sums for each nucleotide('A', 'C', 'G', 'T') up to each position in the DNA sequence S.Let's break down how this is done:
// 
// Initialization:
// 
// We initialize a 2D vector prefix_sums of size 4 x (N + 1), where N is the length of the DNA sequence S.
// Each row of the prefix_sums vector corresponds to a nucleotide('A', 'C', 'G', 'T'), and each column corresponds to a position in the DNA sequence S.
// We initialize all elements of the prefix_sums vector to 0.
// Calculating Prefix Sums :
// 
// We iterate through each character in the DNA sequence S.
// For each character at position i, we update the prefix sums in the prefix_sums vector accordingly :
// If the character is 'A', we increment the value in the 'A' row of the prefix_sums vector at position i + 1 (since we start indexing from 1).
// If the character is 'C', we increment the value in the 'C' row of the prefix_sums vector at position i + 1.
// If the character is 'G', we increment the value in the 'G' row of the prefix_sums vector at position i + 1.
// If the character is 'T', we increment the value in the 'T' row of the prefix_sums vector at position i + 1.
// By doing this, each element in the prefix_sums vector represents the count of the corresponding nucleotide up to that position in the DNA sequence S.
// Result :
// 
//     After completing the preprocessing step, the prefix_sums vector contains the prefix sums for each nucleotide up to each position in the DNA sequence S.
//     These prefix sums allow us to efficiently determine the count of each nucleotide within any specified range[P[K], Q[K]] during the query processing step, leading to faster query execution.


#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q)
{
    int N = S.size();
    int M = P.size();
    vector<int> result;

    // Preprocess to calculate prefix sums for each nucleotide up to each position
    // The prefix_sums vector is a 2D vector where each row represents a nucleotide('A', 'C', 'G', 'T') and each column represents a position in the DNA sequence S.
    // For example, if prefix_sums[0][3] contains the value 2, it means that up to position 3 in the DNA sequence S, there are 2 occurrences of the nucleotide 'A'.
    // Similarly, if prefix_sums[1][5] contains the value 3, it means that up to position 5 in the DNA sequence S, there are 3 occurrences of the nucleotide 'C'.
    // In other words, each element prefix_sums[i][j] represents the count of the nucleotide corresponding to row i(0 for 'A', 1 for 'C', 2 for 'G', 3 for 'T') up to position j in the DNA sequence S.
    // Therefore, by storing these prefix sums in the prefix_sums vector, we can efficiently determine the count of each nucleotide within any specified range[P[K], Q[K]] during the query processing step.
    // This helps optimize the solutionand reduce the time complexity of processing each query.
    vector<vector<int>> prefix_sums(4, vector<int>(N + 1, 0));
    for (int column = 0; column < N; ++column)
    {
        for (int row = 0; row < 4; ++row)
        {
            // Propagate previous value to the new column
            // to potentially increment it later in the if statement
            prefix_sums[row][column + 1] = prefix_sums[row][column];
        }
        if (S[column] == 'A') prefix_sums[0][column + 1]++;
        else if (S[column] == 'C') prefix_sums[1][column + 1]++;
        else if (S[column] == 'G') prefix_sums[2][column + 1]++;
        else if (S[column] == 'T') prefix_sums[3][column + 1]++;
    }

    // Process each query
    for (int k = 0; k < M; ++k)
    {
        int start = P[k];
        int end = Q[k];

        // Determine the minimal impact factor within the specified range [P[K], Q[K]]
        for (int j = 0; j < 4; ++j)
        {
            int count = prefix_sums[j][end + 1] - prefix_sums[j][start];
            if (count > 0)
            {
                result.push_back(j + 1);
                break;
            }
        }
    }

    return result;
}