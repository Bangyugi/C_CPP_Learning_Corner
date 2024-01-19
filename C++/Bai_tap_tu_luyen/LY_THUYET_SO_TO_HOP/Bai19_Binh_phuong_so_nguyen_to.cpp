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

bool checkSoDep(long long n)
{
    bool check = true;
    long long ans = 0;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        long long cnt = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt == 1)
            {
                check = false;
            }
        }
    }
    if (n != 1) 
    {
        check = false;
    }
    return check;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (long long i = a; i <= b; i++)
    {
        if (checkSoDep(i))
        {
            cout << i << " ";
        }
    }
}