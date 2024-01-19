#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
int parent[10001];
bool check = false;

void BFS(int u, set<int> adj[],int i)
{
    queue<int> q;
    q.push(u);
    visited[u] = i;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto v : adj[x])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v]=i;
                parent[v] = x;
            }
            else
            {
                if (parent[x] != v && visited[v]==i)
                {
                    check = true;
                }
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(i, adj, i);
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