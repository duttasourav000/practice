// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other. 

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool checkPermutation(string s, string t)
{
    if (s.size() != t.size())
        return false;

    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;

    for (int i = 0; i < t.size(); i++)
        if (t[i] >= 65 && t[i] <= 90)
            t[i] += 32;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i])
            return false;

    return true;
}

int main(void)
{
    string s, t;
    s = "abcd";
    t = "acdb";
    cout << checkPermutation(s, t) << endl;

    s = "abcd";
    t = "acdba";
    cout << checkPermutation(s, t) << endl;

    s = "abcd";
    t = "eacdb";
    cout << checkPermutation(s, t) << endl;

    s = "a";
    t = "A";
    cout << checkPermutation(s, t) << endl;

    return 0;
}