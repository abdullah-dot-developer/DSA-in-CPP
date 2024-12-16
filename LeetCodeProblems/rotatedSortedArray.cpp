#include <iostream>
#include <vector>

using namespace std;

int rotatedSorted(vector<int> arr, int target)
{
    int n = arr.size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[st] <= arr[mid])
        { // left half is sorted
            if (arr[st] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        { // Right half is sorted
            if (arr[mid] <= target && target <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    cout << "Rotated Sorted array" << endl;

    // The rotated sorted array will be like the one half on either right or left side of mid will be sorted rest not
    // We will take the start value and then we will find the mid value then we compare array at mid is either equal to target or not
    // To decide which half is sorted we will see that whether start value is less then mid value if yes then left will be sorted half else right half will be sorted because any of half will necesserilly be sorted.
    // Then we will apply the binary search on the sorted half arr[mid] <= target <= arr[end] if lies between this domain then search it if not then on right half we will apply binary search using start + (end - start) /2

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    cout << rotatedSorted(arr, target) << endl;
}