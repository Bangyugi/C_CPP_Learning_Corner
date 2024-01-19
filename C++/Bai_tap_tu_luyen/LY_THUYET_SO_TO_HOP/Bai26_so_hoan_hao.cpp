#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

void sinhSoHoanHao(vector<long long> &v)
{
    for (int i = 1; i <= 32; i++)
    {
        if (isPrime(i))
        {
            long long temp = pow(2, i) - 1;
            if (isPrime(temp))
            {
                long long x = temp * pow(2, i - 1);
                v.push_back(x);
            }
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> v;
    sinhSoHoanHao(v);
    for (auto x : v)
    {
        if (x == n)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}