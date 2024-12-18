#include <iostream>
#include <vector>

using namespace std;

// BRUTE FORCE TECHNIQUE ==> Linear Search

// BINARY SEARCH ARRAY
int peakIndex(vector<int> arr)
{
    int st = 1, end = arr.size() - 2; // as our start and end can not be our peak value
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (arr[mid - 1] < arr[mid])
        { // Increasing order => Ignore left side and come on right
            st = mid + 1;
        }
        else // decreasing order => Ignore right side come on left
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Here is Peak index mountain array problem!" << endl;
    // The reason we called it a mountain array because the elements in array are in increasing order initially and then they are in decreasing order making a mountain like structure.
    //  In this problem we need to return the index of that peak value
    // As the array will surely be a mountain array so our first and last index can not be our peak value as they can never construct a mountain.
    // Find the mid and then check whether the mid is peak element or not using condtion
    // arr[mid - 1] < arr[mid] > arr[mid + 1]
    // if not then apply binary search cut the array to half on the condtion if mid is coming in increasing half or increasing slope then peak can not lie on the left of mid check on the right ignore left and vice versa
    // arr[mid - 1 ] < arr[mid ] then we are in increasing half or order in that case ignore the left side and go on right using st = mid + 1 else vice versa.

    vector<int> arr = {0, 3, 8, 9, 5, 2};
    cout << peakIndex(arr) << endl;
}