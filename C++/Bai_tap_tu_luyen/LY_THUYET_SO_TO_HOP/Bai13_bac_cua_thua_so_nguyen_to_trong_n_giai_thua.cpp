#include <bits/stdc++.h>
using namespace std;

long long count(long long n, long long p)
{
    long long ans = 0;
    for (long long i = p; i <= n; i *= p)
    {
        ans += n / i;
    }
    return ans;
}

int main()
{
    long long n, p, x;
    cin >> n >> p;
    x = count(n, p);
    cout << x;
}