#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    int c1 = 0, c2 = n - 1, h1 = 0, h2 = n - 1;
    int x = 1;
    while (c1 <= c2 && h1 <= h2)
    {
        for (int i = c1; i <= c2; i++)
        {
            a[h1][i] = x;
            x++;
        }
        h1++;
        for (int i = h1; i <= h2; i++)
        {
            a[i][c2] = x;
            x++;
        }
        c2--;
        for (int i = c2; i >= c1; i--)
        {
            a[h2][i] = x;
            x++;
        }
        h2--;
        for (int i = h2; i >= h1; i--)
        {
            a[i][c1] = x;
            x++;
        }
        c1++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}