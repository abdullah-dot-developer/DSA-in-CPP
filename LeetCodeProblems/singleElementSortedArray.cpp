#include <iostream>
#include <vector>

using namespace std;

// BRUTE FORCE APPROACH --> O(n)
int singleElement(vector<int> nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}

// OPTIMIZED APPROACH --> Binary Search O(logn)
int singleNonDuplicate(vector<int> nums)
{
    int st = 0, end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        if (mid % 2 == 0)
        {
            // The halfs are even
            if (nums[mid] == nums[mid - 1])
            {
                // Answer will lie in left half
                end = mid - 1;
            }
            else
            {
                // Answer will lie in right half
                st = mid + 1;
            }
        }
        else
        {
            // the halfs are odd
            if (nums[mid] == nums[mid - 1])
            {
                // Answer will lie in right
                st = mid + 1;
            }
            else
            {
                // Answer will lie in left
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    cout << "Problem of Single Element is Sorted Array" << endl;
    // We have given an array in which every element appears twice except a single element which appers at once we have to identify that single element and return that element and array is sorted
    // As in the array containing all duplicates and a single unique value should be an odd array
    // First of all find the mid and you will see that the remaining array on the right and left will be even halfs so now we need to decide whether the left part contain ouor unique value or right part
    // To decide we will compare arr[mid] == arr[mid - 1] answer will exist on left definitely
    //  or arr[mid] == arr[mid +1] asnwer will exist on right definitely bcz it will leave half as a odd array and we know that only odd array can contain single unique value

    vector<int> nums = {1, 2, 2, 3, 3, 4, 4};
    // cout << singleElement(nums) << endl;
    cout << singleNonDuplicate(nums) << endl;
}