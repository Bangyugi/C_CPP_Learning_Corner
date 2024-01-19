#include <bits/stdc++.h>
using namespace std;

int a[100000];
int final = 0;

void sinh(int n, int k)
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    sinh(n, k);
    if (final == 1)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
    }
    else
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << " ";
        }
}