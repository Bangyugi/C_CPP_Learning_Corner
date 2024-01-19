#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long luyThua(long long n)
{
    long long res = 1;
    long long a = 1378;
    a %= 10;
    while (n)
    {
        if (n % 2 == 1)
        {
            res *= a;
            res %= 10;
        }
        a *= a;
        n /= 2;
        a %= 10;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    cout << luyThua(n);
}