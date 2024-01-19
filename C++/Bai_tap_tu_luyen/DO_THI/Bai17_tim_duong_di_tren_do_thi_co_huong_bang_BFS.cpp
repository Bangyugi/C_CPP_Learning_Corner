#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
int parent[10001];

void BFS(vector<int> adj[], int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto v : adj[temp])
        {
            if (!visited[v])
            {
                q.push(v);
                parent[v] = temp;
                visited[v] = 1;
            }
        }
    }
}

void path(int s, int f)
{
    if (!visited[f])
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> res;
        while (s != f)
        {
            res.push_back(f);
            f = parent[f];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (auto x : res)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    BFS(adj, s);
    path(s, f);

    return 0;
}