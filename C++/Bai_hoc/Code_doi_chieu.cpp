#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
vector<int> adj[10001];
bool visited[10001];
bool AP[10001];
int disc[10001], low[10001];
int timer = 0;
int n, m;

void DFS(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int child = 0;
    for (auto x : adj[u])
    {
        if (x == parent)
        {
            continue;
        }
        if (!visited[x])
        {
            DFS(x, u);
            child++;
            low[u] = min(low[u], low[x]);
            if (parent != -1 && disc[u] <= low[x])
            {
                AP[u] = true;
            }
        }
        else
        {
            low[u] = min(low[u], disc[x]);
        }
        
    }
    if (parent == -1 && child > 1)
        {
            AP[u] = true;
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
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (AP[i])
        {
            // cout << i << " ";
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}