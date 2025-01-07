#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> arr, int n, int m, int maxAllowedTime) // O(log(sum) * n )
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m;
}

int minimumTimeToPaint(vector<int> arr, int n, int m)
{
    int sum = 0, maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, n, m, mid)) // then go in left of mid
        {
            ans = mid;
            end = mid - 1;
        }
        else // right of the mid value
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cout << "This is Painter's Partition Problem!" << endl;
    // We are given with the array lengths and each length requires each second to be painted and we are also given with the painters number to whom the work will be allocated. First of all find the minimum amount of time the painter can complete the board painting which means that all different boards will be assigned to all different painters and the paintings will be completed in very less time and the maximum time will be the given maximum length, which is min(40, 50, 60, 34) and also find the scenario for maximum time the painter will take which means only one painter will do all the board painting in that case the required time will become the sum of all the given lengths in an array.
    // That is our range of time in which the painter will complete the painting. Now find the mid of that range and check if the mid is the minimum time the painter will take to complete the painting or not. If the mid is the minimum time then we will check for the left side of the mid and if the mid is not the minimum time then we will check for the right side of the mid. We will keep on checking until we get the minimum time the painter will take to complete the painting.

    vector<int> arr = {40, 30, 10, 20};
    int m = 2;

    int n = arr.size();

    cout << minimumTimeToPaint(arr, n, m) << endl;