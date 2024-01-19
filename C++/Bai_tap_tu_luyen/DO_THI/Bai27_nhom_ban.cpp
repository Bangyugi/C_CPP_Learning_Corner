#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

vector<int> adj[100005];
bool visited[100005];
int Max_value = 0;
int cnt=0;

void DFS(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x);
            cnt++;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt = 1;
            DFS(i);
            Max_value = max(Max_value, cnt);
        }
    }
    cout << Max_value << endl;
    return 0;
}