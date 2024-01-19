#include <bits/stdc++.h>
using namespace std;

bool final = 0;


void sinh(int n, int k, int a[])
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
    int a[k + 1], b[k + 1];
    for (int i = 1; i <= k; i++)
    {
        a[i] = i + 1;
        b[i] = a[i];
    }
    sinh(n, k, a);
    if (!final)
    {
        int cnt = 0;
        for (int i = 1; i <= k; i++)
        {
            if (a[i] != b[i])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    else
        cout << k << endl;
}