#include <bits/stdc++.h>
using namespace std;

long long dem(int n)
{
    long long temp = 1ll * n * n;
    long long tong = temp * (temp - 1) / 2;
    long long co = (n - 1) * (n - 2) * 2 * 2;
    return tong - co;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << dem(i) << endl;
    }
}