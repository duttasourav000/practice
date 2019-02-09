// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures? 

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isUnique(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;

    sort(s.begin(), s.end());
    if (s.size() <= 1)
        return true;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            return false;
    }

    return true;
}

int main(void)
{
    string s;
    s = "abcd";
    cout << isUnique(s) << endl;

    s = "abbcd";
    cout << isUnique(s) << endl;

    s = "a";
    cout << isUnique(s) << endl;

    s = "abcdA";
    cout << isUnique(s) << endl;

    return 0;
}