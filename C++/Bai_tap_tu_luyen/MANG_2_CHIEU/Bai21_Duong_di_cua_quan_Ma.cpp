#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
bool check = false;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void DFS(int i, int j, int n, int u, int v)
{
    if (i == u && j == v)
    {
        check = true;
    }
    a[i][j] = 0;
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1)
        {
            DFS(i1, j1, n, u, v);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int s, t, u, v;
    cin >> s >> t >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    DFS(s, t, n, u, v);
    if (check)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}