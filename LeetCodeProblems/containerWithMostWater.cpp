#include <iostream>
#include <vector>
using namespace std;

// Brute Force =>  Time Complexity = O(n^2)
// 1. Take all possible values
// 2. Calculate how much water they can store
// 3. Fix the right line and then see all possible values with right lines or values
// 4. We will take the distance between two values as one unit
int maxWater(vector<int> height)
{
    int maxWater = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            // Calculating the width between two lines horizontally
            int width = j - i;
            // Calculating the height as our minimum height will be considered b/w two ln
            int hight = min(height[i], height[j]);
            int area = width * hight;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

// TWO-POINTERS OPTIMIZED APPROACH; Time Complexity = O(n)
// We will take two pointers one from right and one from left and we will continue on increasing or decreasing the index of left or right pointers depending on which value is minimum of two the minimum value pointer will be updated each time.

int maxWaterOptimized(vector<int> height)
{
    int n = height.size();
    int leftPointer = 0, rightPointer = n - 1, maxWater = 0;

    while (leftPointer < rightPointer)
    { // as leftPointer = rightPointer the loop ends
        int width = rightPointer - leftPointer;
        int hight = min(height[leftPointer], height[rightPointer]);

        int currWater = width * hight;
        maxWater = max(maxWater, currWater);

        // Whichever the height is less the pointer related to that will be updated
        height[leftPointer] < height[rightPointer] ? leftPointer++ : rightPointer--;
    }
    return maxWater;
}

int main()
{
    cout << "Container with Most water Problem" << endl;
    // Question Understanding
    // Given an array of size[n] having heights of water and we need to return the max amount of water in the container
    // We need to find the two heights constructing a container that can enclose most water we can not deviate the container

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxWaterOptimized(height);
}