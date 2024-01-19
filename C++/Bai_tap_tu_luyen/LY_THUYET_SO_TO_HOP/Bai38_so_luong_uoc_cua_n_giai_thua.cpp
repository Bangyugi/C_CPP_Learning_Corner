#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

bool isPrime(long long n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

long long bacCuaThuaSoNguyenTo(long long n, long long p)
{
    long long res = 0;
    for (long long i = p; i <= n; i *= p)
    {
        res += n / i;
        res %= MOD;
    }
    return res;
}

void runCase()
{
    long long n;
    cin >> n;
    long long res = 1;
    map<long long, int> mp;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            res *= (bacCuaThuaSoNguyenTo(n, i) + 1) % MOD;
            res %= MOD;
        }
    }
    cout << res;
}

int main()
{
    runCase();
}