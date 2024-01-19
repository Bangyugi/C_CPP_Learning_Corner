#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else
        return a.first < b.first;
}

bool soKhongGiam(string n)
{
    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] < n[i - 1])
            return false;
    }
    return true;
}

int main()
{
    string n;
    map<string, int> mp;
    while (cin >> n)
    {
        if (soKhongGiam(n))
        {
            mp[n]++;
        }
    }
    vector<pair<string, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
}