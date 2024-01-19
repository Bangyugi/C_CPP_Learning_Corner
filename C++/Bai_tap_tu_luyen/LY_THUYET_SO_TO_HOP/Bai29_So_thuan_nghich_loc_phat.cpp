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

bool tongChuSo(long long n)
{
    bool check = 0;
    long long sum = 0;
    while (n)
    {
        if (n % 10 == 6)
        {
            check = true;
        }
        sum += n % 10;
        n /= 10;
    }
    if (check)
    {
        if (sum % 10 == 8)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (soThuanNghich(i) && tongChuSo(i))
        {
            cout << i << " ";
        }
    }
}