#include <bits/stdc++.h>
using namespace std;

int p[10000005];

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[a[i]]++;
    }
    for (int i = 0; i <= 10000000; i++)
    {
        if (p[i] != 0)
        {
            cout << i << " " << p[i] << endl;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (p[a[i]] != 0)
        {
            cout << a[i] << " " << p[a[i]] << endl;
            p[a[i]] = 0;
        }
    }
}