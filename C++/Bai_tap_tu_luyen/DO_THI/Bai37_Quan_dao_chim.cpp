#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
vector<int> adj[100005];
bool visited[100005];

void DFS(int u)
{
    visited[u] = true;
    for (auto x: adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
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
    int cnt = 0;
    for (int i = 1; i <= n;i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int temp = 0;
        for (int j = 1; j <= n;j++)
        {
            if (!visited[j])
            {
                temp++;
                DFS(j);
            }
        }
        if (temp>cnt)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}