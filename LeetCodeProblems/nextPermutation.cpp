#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &A, int n)
{
    // 1. Find the pivot
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            pivot = i; // 2
            break;
        }
    }

    // If there is no pivot point in case of array = {4, 3, 2, 1}; Simply reverse the array {1, 2, 3, 4}
    if (pivot == -1)
    {
        reverse(A.begin(), A.end());
        return;
    }

    // 2. next larger element
    for (int i = n - 1; i > pivot; i--) // i > 2
    {
        if (A[i] > A[pivot]) // 4 > 3
        {
            swap(A[i], A[pivot]); // {1, 2, 4, 3}
            break;
        }
    }

    // 3. Reverse (piv+1 to n-1)
    // reverse(A.begin() + pivot + 1, A.end()); // 3, 4
    // Or
    int i = pivot + 1, j = n - 1; // i = 3, j = 3
    while (i <= j)                // equal
    {
        swap(A[i++], A[j--]);
    }
}

void printArray(vector<int> A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Problem: 31 On LeetCode - Next Permutation" << endl;
    // Permutation is the possible combination of the elements of array in different ways like 123 can be arranged in combination as 123, 132, 213, 231, 312, 321
    // Lexicographic next permutation will always be greater number then its previous value.

    vector<int> A = {4, 3, 2, 1};
    int n = A.size();

    nextPermutation(A, n);
    printArray(A, n);
}