#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPages)
        {
            return false;
        }
        if (arr[i] + pages <= maxAllowedPages) // valid solution
        {
            pages += arr[i]; // try on increasing till solution is valid
        }
        else // otherwise increase student and start allocating him from next value
        {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    if (m > n) // students number is greater than books which violates condition bcz each student must get atleast one boook
    {
        return -1;
    }
    // First calculate the sum of all elements of an array as these are our books
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ans = -1;
    // Now apply binary search on this range of books total not on array bcz is not sorted
    int st = 0, end = sum;
    while (st <= end)
    {
        int mid = st + (end - st) / 2; // It is maximum allowed pages

        if (isValid(arr, n, m, mid))
        { // check in left half for best minimum allocation
            ans = mid;
            end = mid - 1;
        }
        else
        { // check in right half for best minimum allocation
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cout << "Book allocation problem" << endl;
    vector<int> arr = {2, 1, 3, 4};

    int n = arr.size(), m = 1; // m is the number of students we can allocate
    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}