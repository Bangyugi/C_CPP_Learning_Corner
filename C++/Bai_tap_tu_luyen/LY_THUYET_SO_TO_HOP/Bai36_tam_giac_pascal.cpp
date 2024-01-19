#include <bits/stdc++.h>
using namespace std;

void runCase()
{
    long long n;
    cin >> n;
    long long a[n + 2][n + 2];

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            a[i][j] = 0;
        }
    }

    a[1][1] = 1;
    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = (a[i - 1][j]%1000000007 + a[i - 1][j - 1]%1000000007)%1000000007;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    runCase();
}