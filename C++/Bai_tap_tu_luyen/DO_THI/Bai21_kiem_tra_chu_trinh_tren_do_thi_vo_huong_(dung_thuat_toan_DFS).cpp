#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
int parent[10001];
bool check = false;

void DFS(int x, set<int> adj[])
{
    visited[x] = 1;
    for (auto v : adj[x])
    {
        if (!visited[v])
        {
            parent[v] = x;
            DFS(v, adj);
        }
        else
        {
            if (parent[x] != v)
            {
                check = true;
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    set<int> adj[10001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj);
        }
    }
    if (check)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}