#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

void runCase()
{
    long long n;
    cin >> n;
    long long res = 0;
    if (n % 2 == 0)
        res = n / 2;
    else
        res = (n - 1) / 2 - n;
    cout << res;
}

int main()
{
    runCase();
}