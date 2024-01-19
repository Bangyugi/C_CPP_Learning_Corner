#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
vector<int> adj[100005];
bool visited[100005];
int a[100005];
int ans = 0;


void DFS(int u, int t)
{
    if (adj[u].size() == 1)
    {
        ans++;
    }
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            if (a[x] == 0)
            {
                DFS(x, 0);
            }
            else if (t + 1 <= m)
            {
                DFS(x, t + 1);
            }
        }
    }               
}

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
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
    DFS(1, a[1]);
    cout << ans;
    
    return 0;
}