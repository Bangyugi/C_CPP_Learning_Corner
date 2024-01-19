#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
bool check = true;
int parent[10001];

void DFS_1(int u, vector<int> adj[])
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS_1(x, adj);
        }
    }
}

void DFS_2(int u, vector<int> adj[])
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            parent[x] = u;
            DFS_2(x, adj);
        }
        else
        {
            if (parent[u] != x)
                check = false;
        }
    }
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
        adj[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS_1(i, adj);
        }
    }
    if (cnt == 1)
    {
        memset(visited, 0, sizeof(visited));
        DFS_2(1, adj);
        if (check)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }

    else
    {
        cout << 0;
    }
    return 0;
}