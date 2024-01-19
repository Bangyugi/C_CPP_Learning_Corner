#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
vector<ii> adj[10005];
bool taken[10005];
int n, m;

void Prim(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    taken[s] = true;
    int d = 0;
    for (ii x : adj[s])
    {
        if (!taken[x.first])
        {
            Q.push({x.second, x.first});
        }
    }
    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        int u = top.second, w = top.first;
        if (!taken[u])
        {
            d += w;
            taken[u] = true;
            for (auto x : adj[u])
            {
                if (!taken[x.first])
                {
                    Q.push({x.second, x.first});
                }
            }
        }
    }
    cout << d << endl;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    Prim(1);
    return 0;
}