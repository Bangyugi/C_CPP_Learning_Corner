#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int cnt = 0;

void Try(int i, int j, int n, int m)
{
    for (int k = 0; k < 2; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 <= n && j1 <= m)
        {
            if (i1 == n && j1 == m)
            {
                cnt++;
            }
            else
            {
                Try(i1, j1, n, m);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 1, n, m);
    cout << cnt;
}