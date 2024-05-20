#include <bits/stdc++.h>
using namespace std;

long long d, x, y;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

long long ext_gcd(long long a, long long b)
{
    long long n = b;
    long long m = a;
    long long xm = 1;
    long long ym = 0;
    long long xn = 0;
    long long yn = 1;
    while (m != 0)
    {
        long long q = n / m;
        long long r = n % m;
        long long xr = xn - q * xm, yr = yn - q * ym;
        n = m;
        m = r;
        xn = xm;
        yn = ym;
        xm = xr;
        ym = yr;
    }
    return xn;
}

int main()
{
    long long a, b;
    cin >> a;
    cin >> b;
    if (gcd(a, b) != 1)
    {
        return 0;
    }
    else
    {
        long long res = ext_gcd(a, b);
        if (res < 0)
        {
            res = res + b;
        }
        cout <<  res << endl;
    }
}