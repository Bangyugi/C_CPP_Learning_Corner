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

    int n;
    cin >> n;
    vector<pair<int, int>> edge;
    vector<int> adj[10001];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                if (j < i)
                    edge.push_back({i, j});
                adj[i].push_back(j);
            }
        }
    }
    sort(edge.begin(), edge.end());
    for (auto x : edge)
    {
        cout << x.first << " " << x.second << "\n";
    }
    cout << endl;
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