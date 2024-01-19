#include <bits/stdc++.h>
using namespace std;

bool soThuanNghich(long long n)
{
    long long m = n;
    long long temp = 0;
    while (n)
    {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp == m;
}

bool uocSoNguyenTo(long long n)
{
    long long ans = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ans++;
        }
    }
    if (n != 1)
    {
        ans++;
    }
    return ans >= 3;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    bool check = false;
    for (long long i = a; i <= b; i++)
    {
        if (soThuanNghich(i) && uocSoNguyenTo(i))
        {
            check = true;
            cout << i << " ";
        }
    }
    if (!check)
    {
        cout << -1;
    }
}