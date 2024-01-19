#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int demSoNguyenTo(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

long long tichCacPhanTu(int a[], int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * a[i] % 1000000007;
        res = res % 1000000007;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int Max = INT_MIN;
    int Min = INT_MAX;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max)
        {
            Max = a[i];
            index = i;
        }
    }
    cout << Max << " " << index << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= Min)
        {
            Min = a[i];
            index = i;
        }
    }
    cout << Min << " " << index << endl;
    cout << demSoNguyenTo(a, n) << endl;
    bool checkReverse = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            checkReverse = false;
            break;
        }
    }
    sort(a, a + n);
    long long max_val = max(a[0] * a[1], a[n - 1] * a[n - 2]);
    cout << max_val << endl;
    if (checkReverse)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    cout << tichCacPhanTu(a, n) << endl;
}