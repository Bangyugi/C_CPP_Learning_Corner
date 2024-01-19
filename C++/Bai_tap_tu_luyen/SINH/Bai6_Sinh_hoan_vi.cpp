#include <bits/stdc++.h>
using namespace std;

int a[100000];
int final = 0;

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = n - i + 1;
    }
}

void sinh(int n)
{
    int i = n - 1;
    while (i >= 1 && a[i] < a[i + 1])
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
        while (a[i] < a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1, greater<>());
    }
}

int main()
{
    int n;
    cin >> n;
    init(n);
    while (final == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh(n);
    }
}