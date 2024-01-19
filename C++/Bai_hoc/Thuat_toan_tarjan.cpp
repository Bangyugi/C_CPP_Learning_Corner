#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int n, m;
int timer = 0;
vector<int> adj[10001];
bool visited[10001];
int disc[10001], low[10001];
stack<int> st;
bool in_stack[10001];
int scc = 0;

void DFS(int u)
{
    visited[u] = true;
    in_stack[u] = true;
    st.push(u);
    disc[u] = low[u] = ++timer;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
            low[u] = min(low[u], low[x]);
        }
        else
        {
            low[u] = min(low[u], disc[x]);
        }
    }
    if (disc[u] == low[u])
    {
        scc++;
        while (st.top() != u)
        {
            cout << st.top() << " ";
            in_stack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        in_stack[st.top()] = false;
        st.pop();
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
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << disc[i] << " " << low[i] << endl;
    // }
    cout << scc << endl;
    return 0;
}