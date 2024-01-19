#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans += i;
            if (n / i != i)
            {
                ans += n / i;
            }
        }
    }
    cout << ans;
}