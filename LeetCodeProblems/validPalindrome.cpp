#include <iostream>
#include <string>
#include <cctype> //for isalnum => alpha numeric built in function

using namespace std;

bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int st = 0, end = s.size() - 1;

    while (st < end)
    {
        if (isAlphaNumeric(!s[st]))
        { // if number is not in A-Z, a-z, 1-9
            st++;
            continue;
        }
        if (isalnum(s[end]))
        {
            end--;
            continue;
        }
        // if not equal then return false
        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        // Update the start and decrease the end
        st++;
        end--;
    }

    return true;
}

int main()
{
    string s = "madam";
    // LeetCode: 125) We need to reverse the string and if it is same as original one even after reversing then that string is palindrome
    cout << isPalindrome(s) ? "True" : "False";
    return 0;
}