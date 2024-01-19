#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
// bool visited[10001];
int connectedComponents[10001];

void DFS(vector<int> adj[], int u, int count)
{
    connectedComponents[u] = count;
    for (auto x : adj[u])
    {
        if (!connectedComponents[x])
            DFS(adj, x, count);
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);

    vector<int> adj[10001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        count++;
        if (!connectedComponents[i])
            DFS(adj, i, count);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (connectedComponents[u] == connectedComponents[v])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}