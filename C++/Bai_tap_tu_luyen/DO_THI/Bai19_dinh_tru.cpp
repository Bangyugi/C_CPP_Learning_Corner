#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];

void DFS(int x, vector<int> adj[])
{
    visited[x] = 1;
    for (auto v : adj[x])
    {
        if (!visited[v])
        {
            DFS(v, adj);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    int n, m;
    cin >> n >> m;
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
    int connectedComponents = 0;
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            connectedComponents++;
            DFS(j, adj);
        }
    }
    int res = 0;
    // vector<int>temp;
    for (int i = 1; i <= n; i++)
    {

        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                cnt++;
                DFS(j, adj);
            }
        }
        if (cnt > connectedComponents)
        {
            res++;
            // temp.push_back(i);
        }
    }
    cout << res << endl;
    // for(auto x: temp)
    // {
    //     cout<<x<<" ";
    // }

    return 0;
}