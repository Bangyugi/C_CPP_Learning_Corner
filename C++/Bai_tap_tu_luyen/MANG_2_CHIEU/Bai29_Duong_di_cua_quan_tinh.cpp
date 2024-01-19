#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};

int cnt = 0;

void DFS(int i, int j, int n)
{
    cnt++;
    a[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 0)
        {
            DFS(i1, j1, n);
        }
    }
}

int main()
{
    int n, s, t;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    DFS(s, t, n);
    cout << cnt;
}