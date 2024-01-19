#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void DFS(int i, int j, int n, int m)
{
    int i1 = i;
    int j1 = j;
    a[i][j] = 0;
    for (int k = 0; k < 8; k++)
    {
        i1 = i + dx[k];
        j1 = j + dy[k];
        if (a[i1][j1] == 1 && i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)
            DFS(i1, j1, n, m);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                cnt++;
                DFS(i, j, n, m);
            }
        }
    }
    cout << cnt;
}