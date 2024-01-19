#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool check = false;

void duongDi(int i, int j, int n, int m, int u, int v)
{
    a[i][j] = 0;
    if (i == u && j == v)
    {
        check = true;
    }
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1)
        {
            duongDi(i1, j1, n, m, u, v);
        }
    }
}

int main()
{
    int n, m, s, t, u, v;
    cin >> n >> m;
    cin >> s >> t >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    duongDi(s, t, n, m, u, v);
    if (check)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
