#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE TECHNIQUE
// vector<int> pairSum(vector<int> nums, int targetSum)
// {
//     vector<int> ans;
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] + nums[j] == targetSum)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }

// TWO POINTER APPROACH
// We will start an index from start and from end(n - 1) and see that whether the pairSum is greater than targetSum if yes then we need to decrease our last index value to 2nd last index value as if we are dealing with ascending sorted array because in that kind of array the value will just continue to increase not decrease we will take benefit of that. Now if pairSum is lower than targetSum then we need to increase our first index value to 2nd and continue to do that unless we reach to position when pairSum will be equal to targetSum that will be our answer.
vector<int> pairSum(vector<int> nums, int targetSum)
{
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n - 1;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum > targetSum)
        {
            j--;
        }
        else if (pairSum < targetSum)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 7, 11, 15};
    int targetSum = 17; // we need to return the pair  whose sum will be 9 in this case (2, 7) is ans
    // For further understanding we will make a pair unique pair of every interger like here the pairs will be: (2, 7), (2, 11), (2, 15), (7, 11), (7, 15), (11, 15)
    vector<int> ans = pairSum(nums, targetSum);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}