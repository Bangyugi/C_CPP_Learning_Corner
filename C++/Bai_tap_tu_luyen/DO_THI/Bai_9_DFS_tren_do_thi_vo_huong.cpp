#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int a[10001][10001];
bool visited[10001];

void DFS(int s, vector<int> adj[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto x : adj[s])
    {
        if (visited[x] == false)
        {
            DFS(x, adj);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);
    vector<int> adj[10001];
    int n, m, s;
    cin >> n >> m >> s;
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
    DFS(s, adj);

    return 0;
}