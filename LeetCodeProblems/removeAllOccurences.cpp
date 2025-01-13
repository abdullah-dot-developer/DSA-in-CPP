#include <iostream>
#include <string>

using namespace std;

string removeOccurences(string s, string target)
{
    while (s.length() > 0 && s.find(target) < s.length())
    {
        s.erase(s.find(target), target.length()); // as s.find(target) will return the starting position of target and target.length() defines number of characters to be erased as we are erasing all occurenes
    }
    return s;
}

int main()
{
    string s = "axxxxyyyyb";
    string target = "xy";

    // AS the target is abc we will use s.find("abc") it will return the starting position of the sub-string passed in find function from start
    // check if the value is valid by evaluating condition s.find("abc") < s.length
    // Then delete or erase starting from index and then give the last index to where you want it to delete to

    cout << removeOccurences(s, target);
    return 0;
}