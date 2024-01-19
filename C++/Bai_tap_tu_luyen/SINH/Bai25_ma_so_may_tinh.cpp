#include <bits/stdc++.h>
using namespace std;

void sinh(int a[], int n, bool &final)
{
    int i = n;
    while (i >= 1 && a[i] == n)
    {
        i--;
    }
    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= n; j++)
        {
            a[j] = 1;
        }
    }
}

int main()
{
    int n;
    // cin >> n;
    cin >> n;
    char a[n + 1];
    int b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = 'A' - 1 + i;
    }
    do
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = 1;
        }
        bool final = false;
        while (!final)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i];
            }
            for (int i = 1; i <= n; i++)
            {
                cout << b[i];
            }
            cout << endl;
            sinh(b, n, final);
        }
    } while (next_permutation(a + 1, a + n + 1));
}