// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
// drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool palindromePermutation(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;

    sort(s.begin(), s.end());
    int i = 0;
    int c = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            i++;
        }
        else
        {
            if (i == s.size() - 1)
            {
                c++;
                i++;                
            }
            else
            {
                if (s[i] == s[i + 1])
                {
                    i += 2;
                }
                else
                {
                    i++;
                    c++;
                }
            }
        }

        if (c == 2)
            return false;
    }

    return true;
}

int main(void)
{
    string s;
    s = "abc dbca";
    cout << palindromePermutation(s) << endl;

    s = "abc ebcad";
    cout << palindromePermutation(s) << endl;

    s = "a b c d b c A";
    cout << palindromePermutation(s) << endl;

    s = "abc abc";
    cout << palindromePermutation(s) << endl;

    s = "abc dbca";
    cout << palindromePermutation(s) << endl;

    s = "abc";
    cout << palindromePermutation(s) << endl;

    s = "bb";
    cout << palindromePermutation(s) << endl;

    s = "Tact Coa";
    cout << palindromePermutation(s) << endl;

    return 0;
}