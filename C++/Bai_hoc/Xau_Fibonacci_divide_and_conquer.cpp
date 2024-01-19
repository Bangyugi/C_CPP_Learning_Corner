#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
ll F[100];

void init()
{
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
}

char fibo(ll n, ll k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= F[n - 2])
    {
        return fibo(n - 2, k);
    }
    else
    {
        return fibo(n - 1, k - F[n - 2]);
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;
    init();
    cout << fibo(n, k) << endl;
    return 0;
}