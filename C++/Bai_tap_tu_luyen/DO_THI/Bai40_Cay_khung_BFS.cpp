#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m, s;
vector<int> adj[100005];
bool visited[100005];
vector<ii> res;

void BFS(int u)
{
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for (auto x: adj[top])
        {
            if (!visited[x])
            {
                res.push_back({top, x});
                visited[x] = true;
                Q.push(x);
            }
        }
    }
}

void nhap()
{
    cin >> n >> m >> s;
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
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    BFS(s);
    for (auto x : res)
    {
        cout << x.first << "->" << x.second << endl;
    }
    return 0;
}