#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.size() == 8)
    {
        s.insert(0, "0");
        s.insert(3, "0");
    }
    else if (s.size() == 9)
    {
        if (s[2] == '/')
        {
            s.insert(3, "0");
        }
        else if (s[1] == '/')
        {
            s.insert(0, "0");
        }
    }
    cout << s;
}