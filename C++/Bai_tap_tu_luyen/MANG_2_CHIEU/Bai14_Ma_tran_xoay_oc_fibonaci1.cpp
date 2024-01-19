#include <bits/stdc++.h>
using namespace std;

long long f[90];

void fibonacci()
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 93; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int main()
{
    int n;
    cin >> n;
    long long a[n][n];
    fibonacci();
    int c1 = 0, c2 = n - 1, h1 = 0, h2 = n - 1;
    int j = 0;
    while (c1 <= c2 && h1 <= h2)
    {
        for (int i = c1; i <= c2; i++)
        {
            a[h1][i] = f[j];
            j++;
        }
        h1++;
        for (int i = h1; i <= h2; i++)
        {
            a[i][c2] = f[j];
            j++;
        }
        c2--;
        for (int i = c2; i >= c1; i--)
        {
            a[h2][i] = f[j];
            j++;
        }
        h2--;
        for (int i = h2; i >= h1; i--)
        {
            a[i][c1] = f[j];
            j++;
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