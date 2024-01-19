#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s.size()==1)
    {
        cout << s;
    }
    else
    {
        while (s[0] == '0')
        {
            s.erase(0, 1);
        }
        for (int i = 0; i < s.size(); i++)
        {

            cout << s[i];
        }
    }
}