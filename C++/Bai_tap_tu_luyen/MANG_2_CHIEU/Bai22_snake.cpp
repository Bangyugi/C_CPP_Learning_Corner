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
    int i = 1;
    while (i <= n)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        i++;
    }
}