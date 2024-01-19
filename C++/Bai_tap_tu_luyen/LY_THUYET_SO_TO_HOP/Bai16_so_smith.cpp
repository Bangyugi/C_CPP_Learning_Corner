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

long long chuso(long long n)
{
    long long sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long thuaSoNguyenTo(long long n)
{
    long long sum = 0;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                sum += chuso(i);
            }
        }
    }
    if (n != 1)
    {
        sum += chuso(n);
    }
    return sum;
}

int main()
{
    long long n;
    cin >> n;
    if ((chuso(n) == thuaSoNguyenTo(n)) && !isprime(n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}