#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool cacChuSo(int n)
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

bool tongChuSo(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    if (isPrime(sum) )
    {
        return true;
    }
    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (cacChuSo(i) && isPrime(i) && tongChuSo(i) )
        {
            cnt++;
        }
    }
    cout << cnt;
}