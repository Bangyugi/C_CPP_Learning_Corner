#include <bits/stdc++.h>
using namespace std;

int p[10000005];

void sangsnt()
{
    for (int i = 2; i <= 10000005; i++)
    {
        p[i] = 1;
    }
    for (int i = 2; i <= sqrt(10000005); i++)
    {
        if (p[i] == 1)
            for (int j = i * i; j <= 10000005; j += i)
            {
                p[j] = 0;
            }
    }
}

int main()
{
    int n, t;
    cin >> n;
    sangsnt();
    while (n--)
    {
        cin >> t;
        if (p[t] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}