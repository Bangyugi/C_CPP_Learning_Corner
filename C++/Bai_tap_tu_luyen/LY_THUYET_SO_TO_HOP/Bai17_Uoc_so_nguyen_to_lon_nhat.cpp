#include <bits/stdc++.h>
using namespace std;

bool isprime(long long n)
{
    if (n < 2)
    {
        return 0;
    }
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

long long thuaSoNguyenTo(long long n)
{
    long long ans = 0;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                ans = i;
            }
        }
    }
    if (n != 1)
    {
        ans = n;
    }
    return ans;
}

int main()
{
    int t;
    long long n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << thuaSoNguyenTo(n) << endl;
    }
}