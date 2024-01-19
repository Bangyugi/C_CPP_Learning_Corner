#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
int Parent[10001];

void BFS(vector<int> adj[], int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto v : adj[temp])
        {
            if (!visited[v])
            {
                q.push(v);
                Parent[v] = temp;
                visited[v] = 1;
            }
        }
    }
}

void path(int u, int v)
{
    if (!visited[v])
    {
        cout << -1;
    }
    else
    {
        vector<int> res;
        while (u != v)
        {
            res.push_back(v);
            v = Parent[v];
        }
        res.push_back(u);
        reverse(res.begin(), res.end());
        for (auto x : res)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    BFS(adj, s);
    path(s, f);
    return 0;
}