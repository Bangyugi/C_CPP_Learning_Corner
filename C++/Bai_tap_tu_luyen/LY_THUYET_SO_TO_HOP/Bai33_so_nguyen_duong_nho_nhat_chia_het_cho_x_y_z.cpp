#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

void runCase()
{
    long long x, y, z, n;
    cin >> x >> y >> z >> n;

    long long temp = lcm(lcm(x, y), z);
    long long m = (long long)pow(10, n - 1);
    long long p = (long long)pow(10, n);
    long long res = (m + temp - 1) / temp * temp;
    if (res < p)
    {
        cout << res;
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    runCase();
}