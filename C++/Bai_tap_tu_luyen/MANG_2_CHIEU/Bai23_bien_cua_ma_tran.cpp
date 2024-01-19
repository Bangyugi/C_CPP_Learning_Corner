#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int c1 = 1, c2 = n, h1 = 1, h2 = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == h1 || i == h2 || j == c1 || j == c2)
            {
                cout << a[i][j] << " ";
            }
        }
    }
}