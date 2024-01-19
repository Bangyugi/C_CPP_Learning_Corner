#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

vector<int> topo;
int visited[10001];

void DFS(int u, vector<int> adj[])
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x, adj);
        }
    }
    topo.push_back(u);
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj);
        }
    }
    reverse(topo.begin(), topo.end());
    for (auto x : topo)
    {
        cout << x << " ";
    }
    return 0;
}