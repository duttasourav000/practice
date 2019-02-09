// String Rotation:Assumeyou have a method isSubstring which checks if one word is a substring
// of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
// call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").

#include <iostream>
#include <string>

using namespace std;

bool rotation(string s1, string s2)
{
    string s = s2 + s2;
    return s.find(s1) != string::npos;
}

int main(void)
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << rotation(s1, s2) << endl;

    s1 = "waterbottle";
    s2 = "erbottlwat";
    cout << rotation(s1, s2) << endl;

    s1 = "waterbottle";
    s2 = "rebottlewat";
    cout << rotation(s1, s2) << endl;
}