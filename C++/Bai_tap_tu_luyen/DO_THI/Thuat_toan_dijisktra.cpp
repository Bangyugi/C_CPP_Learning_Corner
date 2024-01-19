#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
vector<ii> adj[100005];

void dijkstra(int s)
{
    vector<int> shortestPath(n + 1, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    shortestPath[s] = 0;
    Q.push({shortestPath[s], s});
    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        int u = top.second, distance = top.first;
        if (distance > shortestPath[u])
            continue;
        for (ii nextEdge : adj[u])
        {
            int w = nextEdge.second, v = nextEdge.first;
            if (shortestPath[u] + w < shortestPath[v])
            {
                shortestPath[v] = shortestPath[u] + w;
                Q.push({shortestPath[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << shortestPath[i] << endl;
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
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // adj[y].push_back({x, w});
    }
    dijkstra(1);
    return 0;
}
// 7 11
// 1 2 1
// 2 3 2
// 1 7 7
// 1 3 5
// 3 7 3
// 2 5 2
// 2 4 6
// 3 4 4
// 4 5 1
// 4 6 4
// 5 6 7