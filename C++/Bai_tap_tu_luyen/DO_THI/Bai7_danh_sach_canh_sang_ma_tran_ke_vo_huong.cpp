#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int a[10001][10001];

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (auto it : v)
    {
        a[it.first][it.second] = 1;
        a[it.second][it.first] = 1;
    }

    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
