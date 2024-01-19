#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bool check = true;
            for (int k = 0; k < 8; k++)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if (a[i1][j1] >= a[i][j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                cnt++;
                // cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout << cnt;
}