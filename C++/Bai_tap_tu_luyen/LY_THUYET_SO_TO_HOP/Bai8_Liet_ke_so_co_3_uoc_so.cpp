#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n;
    cin >> n;
    for (int i = 0; i <= sqrt(n); i++)
    {
        if (isPrime(i))
        {
            cout << 1ll * i * i << " ";
        }
    }
}