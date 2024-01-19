#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

vector<int> adj[100005];
bool visited[100005];
int maxd;
int maxu;
vector<int> res;

void DFS(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
            if ((int)adj[u].size() > maxd)
            {
                maxd = max(maxd, (int)adj[u].size());
                maxu = u;
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        if (!visited[i])
        {
            maxd = 0;
            maxu = i;
            DFS(i);
            res.push_back(maxu);
        }
    }
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}