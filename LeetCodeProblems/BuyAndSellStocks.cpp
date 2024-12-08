#include <iostream>
#include <vector>

using namespace std;

int maxProfitDay(vector<int> prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > bestBuy)
        { // In this case, the profit is valid
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main()
{
    cout << "Buy and sell stocks." << endl;
    // Buy and sell day of stocks can not be same day. The sell day will be in future.
    // For finding maximum profit you should take buy's least value and sell's highest value of stocks.
    // Best buy for any value is min value in the array starting elements till reached the current element. which means from index 0 to currentIndex - 1
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfitDay(prices);

    return 0;
}