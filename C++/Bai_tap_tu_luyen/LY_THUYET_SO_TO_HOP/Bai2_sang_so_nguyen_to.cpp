#include <bits/stdc++.h>
using namespace std;

int p[10000005];

void sangsnt(int n)
{
    for (int i = 2; i <= n; i++)
    {
        p[i] = 1;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (p[i] == 1)
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
    }
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sangsnt(n);
}