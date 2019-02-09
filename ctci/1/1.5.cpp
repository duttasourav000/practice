// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

#include <string>
#include <iostream>

using namespace std;

string getLower(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    return s;
}

bool areEqual(string s, string t)
{
    if (s.size() != t.size())
        return false;

    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i])
            return false;

    return true;
}

bool oneAway(string s, string t)
{
    s = getLower(s);
    t = getLower(t);

    if (s.size() == t.size())
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
            {
                s[i] = t[i];
                return areEqual(s, t);
            }

        return true;
    }
    else
    {
        if (s.size() + 1 == t.size() || t.size() + 1 == s.size())
        {
            if (s.size() < t.size())
            {
                string z;
                z = s;
                s = t;
                t = z;
            }

            for (int i = 0, j = 0; i < t.size(); i++, j++)
            {
                if (s[i] != t[i])
                {
                    return areEqual(s.substr(0, i) + s.substr(i + 1), t);
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }
}

int main(void)
{
    string s, t;

    s = "pale";
    t = "ple";
    cout << oneAway(s, t) << endl;

    s = "pale";
    t = "pxle";
    cout << oneAway(s, t) << endl;

    s = "pale";
    t = "paxle";
    cout << oneAway(s, t) << endl;

    s = "pAles";
    t = "pale";
    cout << oneAway(s, t) << endl;

    s = "pales";
    t = "ple";
    cout << oneAway(s, t) << endl;

    return 0;
}