#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int visited[10001];
// thuat toan kosaraju
stack<int> st;

void DFS_1(int u, vector<int> adj[])
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS_1(x, adj);
        }
    }
    st.push(u);
}

void DFS_2(int u, vector<int> t_adj[])
{
    visited[u] = 1;
    for (auto x : t_adj[u])
    {
        if (!visited[x])
        {
            DFS_2(x, t_adj);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    vector<int> adj[10001];
    vector<int> t_adj[10001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS_1(i, adj);
        }
    }
    memset(visited, 0, sizeof(visited));
    int scc = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            scc++;
            DFS_2(u, t_adj);
        }
    }
    if (scc == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}