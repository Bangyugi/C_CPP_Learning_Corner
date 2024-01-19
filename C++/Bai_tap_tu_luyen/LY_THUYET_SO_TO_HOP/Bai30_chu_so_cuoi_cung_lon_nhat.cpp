#include <bits/stdc++.h>
using namespace std;

int p[10000001];

void sangsnt(long long n)
{
    for (int i = 0; i <= n; i++)
    {
        p[i] = 1;
    }
    p[0] = p[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (p[i] == 1)
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
    }
}

bool check(int n)
{
    int m = n;
    int max_ = INT_MIN;
    while (n)
    {
        max_ = max(max_, n % 10);
        n /= 10;
    }
    return (m % 10 == max_);
}

int main()
{
    long long n;
    cin >> n;
    sangsnt(n);
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1 && check(i))
        {
            cout << i << " ";
            cnt++;
        }
    }
    cout << endl
         << cnt;
}