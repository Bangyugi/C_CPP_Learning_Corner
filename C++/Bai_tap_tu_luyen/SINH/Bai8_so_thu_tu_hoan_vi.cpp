#include <bits/stdc++.h>
using namespace std;

// int n;
int a[100001];
int final = 0;

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

void sinh(int n)
{
    int i = n;
    while (i >= 1 && a[i] > a[i + 1])
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
    int b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    long long dem = 1;
    init(n);
    while (final == 0)
    {
        bool check = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << dem;
            return 0;
        }
        else
        {
            dem++;
            sinh(n);
        }
    }
}