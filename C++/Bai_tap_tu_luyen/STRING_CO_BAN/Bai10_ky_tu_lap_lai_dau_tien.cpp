#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (!mp.count(s[i]))
            mp[s[i]]++;
        else
        {
            cout << s[i];
            return 0;
        }
    }
    cout << "NONE";
}