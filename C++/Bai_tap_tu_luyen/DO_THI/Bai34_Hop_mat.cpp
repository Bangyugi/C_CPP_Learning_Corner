#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int k, n, m;
vector<int> adj[10005];
bool visited[100005];
int d[100005];

void DFS(int u)
{
    d[u]++;
    visited[u] = true;
    for (auto x: adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
} 

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    cin >> k >> n >> m;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= k;i++)
    {
        memset(visited, false, sizeof(visited));
        DFS(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        if (d[i] == k)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}