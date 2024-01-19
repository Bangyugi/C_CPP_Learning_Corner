#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

vector<int> topo;
int visited[10001];
int degree[10001];

void Kahn(int n, vector<int> adj[])
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        topo.push_back(x);
        q.pop();
        for (auto v : adj[x])
        {
            degree[v]--;
            if (degree[v] == 0)
            {
                q.push(v);
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
    Kahn(n, adj);
    for (auto x : topo)
    {
        cout << x << " ";
    }
    return 0;
}
