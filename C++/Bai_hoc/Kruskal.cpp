#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
int parent[10001];
int sz[10001];

struct edge
{
    int x, y, w;
};

vector<edge> Edge;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    else
    {
        return parent[u] = Find(parent[u]);
    }
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
    {
        return false;
    }
    if (sz[u] < sz[v])
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
    else
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void Kruskal()
{
    sort(Edge.begin(), Edge.end(), cmp);
    vector<edge> path;
    int d = 0;
    for (int i = 0; i < m; i++)
    {
        if (path.size() == n - 1)
        {
            break;
        }
        else
        {
            if (Union(Edge[i].x, Edge[i].y))
            {
                d += Edge[i].w;
                path.push_back(Edge[i]);
            }
        }
    }
    if (path.size() == n - 1)
    {
        cout << d << endl;
        for (auto x : path)
        {
            cout << x.x << " " << x.y << " " << x.w << endl;
        }
    }
    else
    {
        cout << "IMPOSIBLE" << endl;
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
        Edge.push_back({x, y, w});
    }
    // for (auto x : Edge)
    // {
    //     cout << x.x << " " << x.y << " " << x.w << endl;
    // }
    init();
    Kruskal();

    return 0;
}