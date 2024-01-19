#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

vector<int> adj[100005];
int d[10005][10005];
int a[10005][10005];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;

int BFS(int s, int t, int u, int v)
{
    queue<ii> Q;
    Q.push({s, t});
    d[s][t] = 0;
    a[s][t] = 0;
    while (!Q.empty())
    {
        ii top = Q.front();
        Q.pop();
        int i = top.first, j = top.second;
        if (i == u && j == v)
        {
            return d[u][v];
        }
        for (int k = 0; k < 8; k++)
        {
            int i1 = i + dx[k], j1 = j + dy[k];
            if (i1 > 0 && j1 > 0 && i1 <= n && j1 <= n && a[i1][j1])
            {
                a[i1][j1] = 0;
                d[i1][j1] = d[i][j] + 1;
                Q.push({i1, j1});
            }
        }
    }
    return -1;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);

    cin >> n;
    int s, t, u, v;
    cin >> s >> t >> u >> v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << BFS(s, t, u, v);

    return 0;
}