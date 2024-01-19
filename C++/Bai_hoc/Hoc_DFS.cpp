#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
bool visited[10001];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
}

int main()
{
    input();
    DFS(1);
}