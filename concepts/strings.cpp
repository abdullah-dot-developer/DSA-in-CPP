#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str)
{
    string reversed = str; // create a copy
    reverse(reversed.begin(), reversed.end());

    return reversed == str; // if yes return true otherwise false
}

int main()
{
    string str = "madam";

    cout << (isPalindrome(str) ? "true" : "false") << endl;
}