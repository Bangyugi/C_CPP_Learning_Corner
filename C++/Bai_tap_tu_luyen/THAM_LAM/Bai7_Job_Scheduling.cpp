#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    int t = v[0].second;
    int cnt = 1;
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i].first > t)
        {
            cnt++;
            t = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}