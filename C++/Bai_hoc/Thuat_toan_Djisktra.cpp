#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> adj[100005];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra(int s)
{
    vector<int> d(n + 1, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, s});
    d[s] = 0;
    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        int u = top.second;
        int dis = top.first;
        if (dis > d[u])
            continue;
        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << d[i] << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    nhap();
    dijkstra(1);
    return 0;
}
