#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long binpow(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b)
    {
        if (b % 2 == 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        b /= 2;
        a %= MOD;
    }
    return res;
}

void runCase()
{
    long long a, b;
    cin >> a >> b;
    cout << binpow(a, b);
}

int main()
{
    runCase();
}