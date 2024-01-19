#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int n, m;
vector<int> adj[100005];
bool visited[100005];
int d[100005];
int sz[100005];

int DFS(int u)
{
    visited[u] = true;
    int res = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            res += DFS(x);
        }
    }
    return sz[u] = res;
}

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    nhap();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << sz[i] << endl;
    }

    return 0;
}