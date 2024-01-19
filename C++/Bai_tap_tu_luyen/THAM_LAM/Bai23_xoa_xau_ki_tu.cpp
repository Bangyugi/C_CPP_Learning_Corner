#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
bool cmp(string a, string b)
{
    return a.size() > b.size();
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string number;
    vector<string> v;
    while (ss >> number)
    {
        v.push_back(number);
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < (int)v.size(); i += 2)
    {
        cnt += v[i].size();
    }
    cout << cnt;

    return 0;
}