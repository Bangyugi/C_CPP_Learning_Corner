#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void DFS(int i, int j, int n, int m, int &cnt)
{
    cnt++;
    a[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1)
        {
            DFS(i1, j1, n, m, cnt);
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
    int max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                int cnt = 0;
                DFS(i, j, n, m, cnt);
                max_val = max(max_val, cnt);
            }
        }
    }
    cout << max_val << endl;
}