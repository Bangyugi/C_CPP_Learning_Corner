#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> adj[10001];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        sort(adj[i].begin(), adj[i].end());
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}