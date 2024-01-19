#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isChinhPhuong(int n)
{
    int m = sqrt(n);
    if (m * m == n && isPrime(m))
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int cnt=0;
    if (n < 6)
    {
        cout << "NO";
    }
    else
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0)
            {
                cnt++;
                if (cnt == 3)
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
        cout << "NO";
    }
    return 0;
}