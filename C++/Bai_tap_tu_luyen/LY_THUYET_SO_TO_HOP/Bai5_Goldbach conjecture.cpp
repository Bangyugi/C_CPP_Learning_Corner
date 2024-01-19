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

bool check(int n)
{
    while (n)
    {
        int x = n % 10;
        if (x != 2 && x != 3 && x != 5 && x != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    sangsnt();
    while (t--)
    {
        cin >> n;
        for (int i = 2; i <= n / 2; i++)
        {
            if (p[i] == 1 && p[n - i] == 1)
            {
                cout << i << " " << n - i << endl;
            }
        }
    }
}