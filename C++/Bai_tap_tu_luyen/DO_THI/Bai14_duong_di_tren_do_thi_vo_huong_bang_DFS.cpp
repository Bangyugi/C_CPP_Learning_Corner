#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int a[10001][10001];
bool visited[10001];
vector<int> path;
bool check = false;

void DFS(int s, vector<int> adj[], int v)
{
    visited[s] = true;

    if (s == v)
    {
        check = true;
    }
    else
        for (auto x : adj[s])
        {
            if (visited[x] == false)
            {
                path.push_back(x);
                DFS(x, adj, v);
                if (!check)
                {
                    path.pop_back();
                }
                else
                {
                    return;
                }
            }
        }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("input.inp", "r", stdin);
    // freopen("output.ans", "w", stdout);
    vector<int> adj[10001];
    int n, m, s, v;
    cin >> n >> m >> s >> v;
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
    path.push_back(s);
    DFS(s, adj, v);
    if (!visited[v])
    {
        cout << -1;
    }
    else
    {
        for (auto x : path)
        {
            cout << x << " ";
        }
    }

    return 0;
}