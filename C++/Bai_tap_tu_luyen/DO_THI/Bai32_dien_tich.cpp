#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int n, m;
char a[10005][10005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ares = 0;

void DFS(int i, int j)
{
    a[i][j] = '#';
    ares++;
    for (int k = 0; k < 4;k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1>0 && j1>0 && i1<=n && j1 <=m && a[i1][j1] == '.')
        {
            DFS(i1, j1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.')
            {
                ares = 0;
                DFS(i, j);
                cout << ares << " ";
            }
        }
    }
 
}
