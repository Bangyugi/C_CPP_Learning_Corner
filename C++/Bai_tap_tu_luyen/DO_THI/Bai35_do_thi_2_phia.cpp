#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

vector<int> adj[100005];
int color[100005];
int n, m;

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
}

bool BFS(int u)
{
    queue<int> Q;
    Q.push(u);
    color[u] = 0;
    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for (auto x: adj[top])
        {
            if (color[x]==-1)
            {
                color[x] = 1 - color[top];
                Q.push(x);
            }
            else if (color[x] == color[top])
            {
                return false;   
            }
        }
    }
    return true;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    nhap();
    bool check = true;
    for (int i = 1; i <= n;i++)
    {
        if (color[i]==-1)
        {
            if (!BFS(i))
            {
                return false;
                break;
            }
        }
    }
    (check) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}