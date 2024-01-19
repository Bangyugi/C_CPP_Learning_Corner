#include <bits/stdc++.h>
using namespace std;

void ThuaSoNguyenTo(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (n != 1)
            {
                cout << i << "^" << cnt << " * ";
            }
            else
            {
                cout << i << "^" << cnt;
            }
        }
    }
    if (n != 1)
    {
        cout << n << "^" << 1;
    }
}

int main()
{
    long long n;
    cin >> n;
    ThuaSoNguyenTo(n);
}