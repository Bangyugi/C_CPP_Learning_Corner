#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
int timer = 0;
vector<int> adj[10001];
bool visited[10001];
int disc[10001], low[10001];
vector<pair<int, int>> edge;

void DFS(int u, int par)
{
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (!visited[v])
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (disc[u] < low[v])
            {
                edge.push_back({u, v});
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, -1);
        }
    }
    cout << edge.size() << endl;
    for (auto x : edge)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}