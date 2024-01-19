#include <bits/stdc++.h>
using namespace std;

long long UCLN(long long a, long long b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

long long BCNN(long long a, long long b)
{
    return a / UCLN(a, b) * b;
}

void runCase()
{
    long long a, b;
    cin >> a >> b;
    cout << UCLN(a, b) << " " << BCNN(a, b);
}

int main()
{
    runCase();
}