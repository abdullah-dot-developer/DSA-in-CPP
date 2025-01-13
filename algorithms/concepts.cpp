#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return true;
    else
        return false;
};

int main()
{
    // vector<pair<int, int>> vec = {{3, 1}, {4, 1}, {6, 2}, {5, 1}};

    // sort(vec.begin(), vec.end(), comparator);

    // for (auto p : vec)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    string s = "abc";

    // next_permutation(s.begin(), s.end());
    // prev_permutation(s.begin(), s.end());

    vector<int> vec = {1, 5, 7, 8};

    cout << *(max_element(vec.begin(), vec.end())) << endl;
    cout << binary_search(vec.begin(), vec.end(), 7) << endl; // return 1 if target exist otherwise return 0

    int n = 15;
    long int n1 = 15;
    long long int n2 = 15;

    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountl(n1) << endl;  // l for showing it is long
    cout << __builtin_popcountll(n2) << endl; // ll for showing it is long long

    return 0;
}