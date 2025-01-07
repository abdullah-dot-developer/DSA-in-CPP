#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &A, vector<int> &B, int m, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;
    while (j >= 0 && i >= 0)
    {
        if (A[i] >= B[j])
        {
            A[idx] = A[i];
            idx--;
            i--;
            // Or
            // A[idx--] = A[i--]
        }
        else
        {
            A[idx] = B[j];
            j--;
            idx--;
            // Or
            // A[idx--] = B[j--]
        }
    }
    while (j >= 0)
    {
        A[idx] = B[j];
        idx--;
        j--;
    }
}

void printArray(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Problem: 88 On LeetCode - Merge 2 sorted arrays" << endl;
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};
    int m = 3, n = 3;

    // We have given with two arrays and we have to sort them in A we have an array of size so that two arrays can be merged with out occupying extra space in place of 0s we will insert the values of second array in ascending order.
    mergeSort(A, B, m, n);
    printArray(A);
}