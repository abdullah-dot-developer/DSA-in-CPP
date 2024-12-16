#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> nums, int target)
{
    int n = nums.size();

    int start = 0, end = n - 1;
    while (start <= end)
    {
        // int mid = (start + end) / 2;
        // In order to prevent from overflow we optimize our code and change the formula for mid to something like this
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else // If our mid is our answer then we will return that
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    // cout << "This is binary Search!" << endl;
    // Binary Search Algorithm works on the sorted array and its time complexity is O(logn) whether the array is sorted ascending or descending

    // STEPS FOR APPLYING BINARY SEARCH
    // First of all find the mid of the sorted array
    // mid = (startIdx + endIdx) / 2
    // then analyze the mid whether it is bigger than target or not if not we will ignore the first half of array and find it in second half and vice versa.
    // According to our half selecton that which half is selected again find the mid of that half do the previos process.

    // vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    vector<int> nums = {
        -1,
        0,
        3,
        4,
        5,
        9,
        12,
        13,
        14,
        20,
    };

    int target = 20;

    cout << "Index of target is: " << binarySearch(nums, target);
}