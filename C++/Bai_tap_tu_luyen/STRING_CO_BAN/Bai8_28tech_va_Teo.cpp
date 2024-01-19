#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        while (s[i] == '2' || s[i] == '8' || s[i] == 't' || s[i] == 'e' || s[i] == 'c' || s[i] == 'h')
        {
            s.erase(i, 1);
        }
    }
    if (s.size()!=0)
    {
        cout << s;
    }
    else
    {
        cout << "EMPTY";
    }
}