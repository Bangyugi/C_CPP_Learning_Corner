#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int n, m, s;
vector<ii> adj[100005];

void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Djisktra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    Q.push({d[s], s});
    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        int u = top.second, dis = top.first;
        if (dis > d[u])
            continue;
        for (auto x : adj[u])
        {
            int v = x.first, e = x.second;
            if (d[v] > d[u] + e)
            {
                d[v] = d[u] + e;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    nhap();
    Djisktra(s);
    return 0;
}