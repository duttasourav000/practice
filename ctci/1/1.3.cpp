// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. 

#include <iostream>
#include <string>

using namespace std;

string URLify(string s)
{
    int p1, p2;
    p1 = s.size() - 1;
    p2 = p1;

    while (p1 >= 0 && s[p1] == ' ')
        p1--;

    while (p1 >= 0)
    {
        if (s[p1] != ' ')
        {
            s[p2] = s[p1];
            p2--;
        }
        else
        {
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
        }

        p1--;
    }

    return s;
}

int main(void)
{
    string s;
    s = "a b v    ";
    cout << URLify(s) << endl;
    
    s = "a b v    ";
    cout << URLify(s) << endl;

    s = "a  b v      ";
    cout << URLify(s) << endl;

    s = "abv";
    cout << URLify(s) << endl;

    s = "";
    cout << URLify(s) << endl;

    return 0;
}