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

    for (long long i = 1; i <= 1000005; i++)
    {
        if (i * i >= a && i * i <= b)
        {
            cout << i * i << " ";
        }
    }
}