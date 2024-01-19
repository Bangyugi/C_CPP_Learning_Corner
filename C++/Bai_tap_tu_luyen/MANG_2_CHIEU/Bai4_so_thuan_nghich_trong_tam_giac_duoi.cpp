#include <bits/stdc++.h>
using namespace std;

bool soThuanNghich(int n)
{
    int m = n;
    int rev = 0;
    while (n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    if (m == rev)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i && soThuanNghich(a[i][j]))
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}