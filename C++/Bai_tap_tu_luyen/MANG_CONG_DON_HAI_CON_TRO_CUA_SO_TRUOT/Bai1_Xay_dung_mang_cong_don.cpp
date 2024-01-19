#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long P[n];
    P[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        P[i] = P[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << P[i] << ' ';
    }
}