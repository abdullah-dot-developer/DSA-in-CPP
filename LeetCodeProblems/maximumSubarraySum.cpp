#include <iostream>

using namespace std;

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = 7;

    // using simple loops
    // for (int st = 0; st < n; st++)
    // {
    //     for (int end = st; end < n; end++)
    //     {
    //         for (int i = st; i <= end; i++)
    //         {
    //             cout << arr[i];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    // USING BRUTE FORCE TECHNIQUE
    // int maxSum = INT_MIN;
    // for (int st = 0; st < n; st++)
    // {
    //     int currSum = 0;
    //     for (int end = st; end < n; end++)
    //     {
    //         currSum += arr[end];
    //         maxSum = max(currSum, maxSum);
    //     }
    // }
    // cout << "Maximum Subarray sum is = " << maxSum << endl;

    // USING KADANE'S ALGORITHMS  ==> Most Optimised way of solving this problem  says that if two the subarray sum is less tehn zero of negative and put it equal to 0;
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << maxSum;
    return 0;
}