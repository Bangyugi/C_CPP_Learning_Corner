#include <bits/stdc++.h>
using namespace std;

long long Lmao(long long n)
{
    long long ans = 0;
    for (long long i = 5; i <= n; i *= 5)
    {
        ans += (n / i) % 1000000007;
        ans %= 1000000007;
    }
    return ans;
}

int main()
{
    long long n;
    cin >> n;
    cout << Lmao(n);
}