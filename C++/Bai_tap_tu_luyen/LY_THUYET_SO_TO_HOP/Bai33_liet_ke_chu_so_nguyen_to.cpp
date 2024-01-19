#include <bits/stdc++.h>
using namespace std;

void runCase(long long n)
{
    map<char, long long> mp;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
        {
            mp[s[i]]++;
        }
    }
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] != 0)
        {
            cout << s[i] << " " << mp[s[i]] << endl;
            mp[s[i]] = 0;
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    runCase(n);
}