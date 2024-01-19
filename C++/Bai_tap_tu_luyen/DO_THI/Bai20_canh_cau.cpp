#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];

void DFS(int x, set<int> adj[])
{
    visited[x] = 1;
    for (auto v : adj[x])
    {
        if (!visited[v])
        {
            DFS(v, adj);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    set<int> adj[10001];
    vector<pair<int, int>> edge;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        edge.push_back({x, y});
    }

    int connectedComponents = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            connectedComponents++;
            DFS(i, adj);
        }
    }

    int res = 0;
    for (auto x : edge)
    {
        adj[x.first].erase(x.second);
        adj[x.second].erase(x.first);
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                DFS(i, adj);
            }
        }
        if (cnt > connectedComponents)
        {
            res++;
        }
        adj[x.first].insert(x.second);
        adj[x.second].insert(x.first);
    }

    cout << res << endl;
    return 0;
}