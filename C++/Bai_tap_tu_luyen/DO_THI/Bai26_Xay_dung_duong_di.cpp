#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
vector<int> adj[1000005];
int visited[1000005];

void DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    vector<int> index;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            index.push_back(i);
            cnt++;
            DFS(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 1; i < (int)index.size(); i++)
    {
        cout << index[i - 1] << " " << index[i] << endl;
    }
    return 0;
}