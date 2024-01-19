#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int n, m;
vector<int> adj[100005];
bool visited[100005];
int sz[100005];

void DFS(int u)
{
    visited[u] = true;
    sz[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
            sz[u] += sz[x];
        }
    }
}

void nhap()
{
    cin >> n;
    for (int i = 0; i < n-1; i++)
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
    DFS(1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += sz[i];
    }
    cout << sum;
    return 0;
}