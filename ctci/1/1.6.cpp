// String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>
#include <string>

using namespace std;

string stringCompression(string s)
{
    if (s.size() < 1)
        return s;

    string sCom = "";
    char c = s[0];
    int ctr = 1, pos = 1;
    while (pos <= s.size())
    {
        if (c != s[pos])
        {
            sCom += c + to_string(ctr);
            c = s[pos];
            ctr = 1;
        }
        else
        {
            ctr += 1;
        }

        pos += 1;
    }

    if (sCom.size() < s.size())
        return sCom;
    else
        return s;
}

int main(void)
{
    string s = "aabcccccaaa";
    cout << stringCompression(s) << endl;

    s = "";
    cout << stringCompression(s) << endl;

    s = "a";
    cout << stringCompression(s) << endl;

    s = "ab";
    cout << stringCompression(s) << endl;

    s = "aa";
    cout << stringCompression(s) << endl;

    s = "aaa";
    cout << stringCompression(s) << endl;

    s = "abcz";
    cout << stringCompression(s) << endl;

    s = "qweeeeee";
    cout << stringCompression(s) << endl;

    return 0;
}