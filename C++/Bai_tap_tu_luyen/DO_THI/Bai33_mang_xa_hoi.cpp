#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m, q;

vector<int> adj[100005];
bool visited[100005];
ll cnt = 0;

void DFS(int s)
{
    cnt++;
    visited[s] = true;
    for (auto x : adj[s])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    cin >> q;
    while (q--)
    {
        for (int i = 0; i < 100005; i++)
        {
            adj[i].clear();
        }
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cnt = 0;
                DFS(i);
                sum += cnt * (cnt - 1) / 2;
            }
        }
        (sum == m) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}