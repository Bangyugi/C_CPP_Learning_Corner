#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int parent[10005];
int sz[10005];
int Max_value = INT_MIN;

void init(int n)
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
        return false;
    if (sz[u] < sz[v])
    {
        parent[u] = v;
        sz[v] += sz[u];
        Max_value = max(Max_value, sz[v]);
    }
    else
    {
        parent[v] = u;
        sz[u] += sz[v];
        Max_value = max(Max_value, sz[u]);
    }
    return true;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt1 = n;
    init(n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (Union(x, y))
        {
            cnt1--;
            cout << cnt1 << " " << Max_value << endl;
        }
    }
    return 0;
}