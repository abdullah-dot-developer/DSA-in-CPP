#include <iostream>
#include <vector>

using namespace std;

// Optimal approach to solve this problem is we will count the number of 0's, 1's, and 2's in the array and then we will update the array with the count of 0's, 1's, and 2's.
void sortedArr(vector<int> &arr, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int idx = 0;

    for (int i = 0; i < count0; i++)
    {
        arr[idx++] = 0; // increase the idx with 1 value after 0 is assigned
    }
    for (int i = 0; i < count1; i++)
    {
        arr[idx++] = 1;
    }
    for (int i = 0; i < count2; i++)
    {
        arr[idx++] = 2;
    }
}

// This is a Dutch National Flag problem.
// Time complexity of this approach is O(n) and space complexity is O(1).
// This is the most optimized approach to solve this problem.
void sortedArrDNF(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArr(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 75. We are given an array having the entries of 0, 1, and 2 only and we have to sort the array in ascending order. just these three numbers are present in the array not any other elements.

    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 0, 2, 1};
    int n = arr.size();

    // sortedArr(arr, n);
    sortedArrDNF(arr, n);
    printArr(arr, n);
}