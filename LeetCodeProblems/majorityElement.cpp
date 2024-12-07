#include <iostream>
#include <vector>
#include <algorithm> //for sorting

using namespace std;

// BRUTE FORCE TECHNIQUE --> Time complexity = O(n^2) big of n square
// int majorityElement(vector<int> nums)
// {
//     int n = nums.size();

//     for (int val : nums)
//     {
//         int frequency = 0; // that how many times an element is present in an array
//         for (int el : nums)
//         {
//             if (el == val)
//             {
//                 frequency++;
//             }
//         }
//         if (frequency > n / 2)
//         {
//             return val;
//         }
//     }
//     return -1;
// }

// OPTIMIZED APPROACH --> Time complexity = O(nlogn)
// int majorityElement(vector<int> nums)
// {
//     int n = nums.size();

//     // Sort the array first
//     sort(nums.begin(), nums.end());

//     // Count frequency
//     int frequency = 1, ans = nums[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             frequency++;
//         }
//         else
//         {
//             frequency = 1;
//             ans = nums[i];
//         }
//         if (frequency > n / 2)
//         {
//             return ans;
//         }
//     }
//     return ans;
// }

// MOORE'S VOTING ALGORITHM
// int majorityElement(vector<int> nums)
// {
//     int n = nums.size();

//     int freq = 0, ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (freq == 0)
//         {
//             ans = nums[i];
//         }
//         if (ans == nums[i])
//         {
//             freq++;
//         }
//         else
//         {
//             freq--;
//         }
//     }
//     return -1;
// }

int main()
{
    // MAJORITY ELEMENT ==> 2/3rd of the majority
    //  We need to divide the size of array to 2 for example 8/2 = 4 or 9/2= 4.5 in 9 case we will just take 4 becasue we need to ask floor(n/2) so the element which exist in array more than 4 that will be the majority element

    vector<int> nums = {1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 5};

    // cout << majorityElement(nums);

    // Matrix Multiplication
    // int A[3][2] = {
    //     {2, 3},
    //     {4, 5},
    //     {6, 7}};
    // int B[2][3] = {
    //     {2, 3, 4},
    //     {5, 6, 7}};

    // int C[3][3] = {0};

    // // Matrix multiplication Logic
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         for (int k = 0; k < 2; k++)
    //         {
    //             C[i][j] += A[i][k] * B[k][j];
    //         }
    //     }
    // }

    // cout << "Resultant Matrix will be: " << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}