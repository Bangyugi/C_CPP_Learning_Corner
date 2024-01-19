#include <bits/stdc++.h>
using namespace std;

long long phanTich(long long n, long long k)
{
    vector<long long> v;
    for (int i = 2; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                v.push_back(i);
            }
        }
    }
    if (n != 1)
    {
        v.push_back(n);
    }
    if (v.size() < k)
    {
        return -1;
    }
    else
    {
        return v[k - 1];
    }
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << phanTich(n, k);
}