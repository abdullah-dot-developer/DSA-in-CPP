#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> arr, int n, int c, int minAllowedDistance) // 4
{
    int cows = 1, lastStallPos = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastStallPos >= minAllowedDistance)
        {
            cows++;
            lastStallPos = arr[i];
        }

        if (cows == c)
        {
            return true;
        }
    }
    return false;
}
int getDistance(vector<int> arr, int n, int c)
{
    sort(arr.begin(), arr.end());
    int st = 1, end = arr[n - 1] - arr[0], ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, c, mid)) // right
        {
            ans = mid;
            st = mid + 1;
        }
        else // left
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cout << "This is aggressive Cows Problem! Available on Spog.com" << endl;
    // We will take start as our minimum possible distance and end as a max possible distance  which means our start will be 1 and end as our last value of array
    //  in while loop, find mid of st and end and then check whether that mid is a possible solution or not
    // If possible then assign the value of mid to ans and then find the value in the right half of the array
    //  if not then find ans in left half of the array
    // Now to check whether our solution is possible value  or not check that number of cows can be placed according to that value of mid on the given array value means if three cows then in an array {1, 2, 8, 4, 9} then the three cows with 4 distance can not be adjusted on this array which means that the mid is not a valid mid
    // Sort the array sort(arr.begin(), arr.end())
    // Our mid is the minimum possible distance.
    // The distance between two cows must be greater then or equal to the mid value
    // These questions were asked by the google amazon and paypal in their interviews of different roles as a developer or software engineers

    vector<int> arr = {1, 2, 8, 4, 9};

    int n = arr.size(), c = 3;

    cout << getDistance(arr, n, c);

    return 0;
}