#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    map<int, int> mp;
    vector<int> v;
    while (cin >> n)
    {
        v.push_back(n);
        if (isPrime(n))
        {
            mp[n]++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (mp[v[i]] != 0)
        {
            cout << v[i] << " " << mp[v[i]] << endl;
            mp[v[i]] = 0;
        }
    }
}