#include <bits/stdc++.h>
using namespace std;

int a[31];
int n, s;
int ans = INT_MAX;
vector<int> v;
int sum = 0;

void Try(int i, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        sum += a[j];
        v.push_back(a[j]);
        if (sum == s)
        {
            ans = min(ans, (int)v.size());
            // for (auto x : v)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        else
        {
            Try(i + 1, j + 1);
        }
        sum -= a[j];
        v.pop_back();
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Try(1, 1);
    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}