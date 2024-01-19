#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];

void BFS(vector<int> adj[], int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto v : adj[x])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    BFS(adj, s);
    return 0;
}