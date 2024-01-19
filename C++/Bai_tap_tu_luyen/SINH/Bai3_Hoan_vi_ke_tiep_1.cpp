#include <bits/stdc++.h>
using namespace std;

int a[100000];
int final = 0;

void sinh(int n)
{
    int i = n - 1;
    while (i >= 0 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        int j = n;
        while (a[j] < a[i])
        {
            j--;
        }
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sinh(n);
    if (final==1)
    {
        for (int i=1;i<=n;i++)
        {
            cout<<i<<' ';
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
}