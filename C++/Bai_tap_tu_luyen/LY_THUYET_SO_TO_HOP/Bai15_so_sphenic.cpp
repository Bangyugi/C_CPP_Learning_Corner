#include <bits/stdc++.h>
using namespace std;

bool soSphenic(long long n)
{
    int ans = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt > 1)
            {
                return false;
            }
            else
                ans++;
        }
    }

    if (n != 1)
        ans++;
    return ans == 3;
}

int main()
{
    long long n;
    cin >> n;
    if (soSphenic(n))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}