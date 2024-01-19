#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int n)
{
    int i = 1, j = n;
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void sinh(int a[], int n, bool &final)
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i] = 1;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
    bool final = 0;
    while (!final)
    {
        if (check(a, n))
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }

        sinh(a, n, final);
    }
}