#include <iostream>
#include <string>

using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    // First check the frequency of s1
    int freq[26] = {0}; // bcz all values will be lowercase english letters means 26
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++; // if s1[i] is b let's say then as freq is of int type so it will be converted into ASCII value for b it is 96 and for a it is 95 every time we are subtracting a from any value in this case answer will be 1 which means on index 1 we will increase the freq by 1
        // create a window of same size on str2 and by sliding find the value
    }
    int windSize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        while (windIdx < windSize && idx < s2.length())
        {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq)) // found
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // LeetCode 567: We have given with two strings s1 and s2 and we need to find the permutations of s1 in given s2 string
    // Like s1 = "ab" its next permutation is ba or any other as we go on and we have s2 = "eidbaooo" and in this case it exist in s2 we need to return true
    // APPROACH ==> find the frequency for s1
    // then in s2 we will check the windows of size of s1
    // then match windwo frequency with frequency of s1
    string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
    return 0;
}