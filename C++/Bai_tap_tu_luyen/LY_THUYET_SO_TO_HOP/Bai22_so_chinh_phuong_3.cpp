#include <bits/stdc++.h>
using namespace std;

bool soChinhPhuong(long long n)
{
    long long temp = sqrt(n);
    if (temp * temp == n)
        return 1;
    else
        return 0;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long cnt = 0;
    for (long long i = sqrt(a); i <= sqrt(b); i++)
    {
        if (i * i >= a && i * i <= b)
        {
            cnt++;
        }
    }
    cout << cnt;
}