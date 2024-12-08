#include <iostream>
#include <vector>

using namespace std;

// Brute Force Approach
vector<int> productExceptSelf(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1); // We took array where we store our answer array it is of size n and initial value is 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                ans[i] *= nums[j];
            }
        }
    }
    return ans;
}

// OPTIMAL SOLUTION
vector<int> productExceptSelfOptimal(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    // vector<int> prefixProd(n, 1);
    // vector<int> suffixProd(n, 1);

    // prefix ==> ans directly store in ans vector
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    // suffix ==> ans directly store in ans vector
    int suffixProd = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffixProd *= nums[i + 1];
        ans[i] *= suffixProd;
    }

    // final answer
    // for (int i = 0; i < n; i++)
    // {
    //     ans[i] = prefixProd[i] * suffixProd[i];
    // }
    return ans;
}

int main()
{
    cout << "Product of Array!" << endl;
    // We need to calculate the product of elements of array except itself and return an array containing products of elements of previos array
    // like if we have an array [1, 2, 3, 4] then answer array would be [24, 12, 8, 6] like on oth inder we will leave 1 and then calculate the product of rest of element and or index 1 leave 2 and store the product of rest of the elements

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productExceptSelfOptimal(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}