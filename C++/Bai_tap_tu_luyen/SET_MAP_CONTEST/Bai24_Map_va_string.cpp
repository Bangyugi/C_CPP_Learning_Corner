#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    map<string, int> mp;
    while (n--)
    {
        cin >> s;
        mp[s]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    string t;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second < min_val)
        {
            min_val = (*it).second;
            t = (*it).first;
        }
    }
    cout << t << " " << min_val << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second > max_val)
        {
            max_val = (*it).second;
            t = (*it).first;
        }
    }
    cout << t << " " << max_val << endl;
}