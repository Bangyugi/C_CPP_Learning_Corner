#include <bits/stdc++.h>
using namespace std;

bool check(long long a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        long long r = n - 1;
        long long l = 0;
        while (l < r)
        {
            long long temp = a[r] * a[r] + a[l] * a[l];
            if (temp == a[i] * a[i])
            {
                return true;
            }
            else if (temp > a[i] * a[i])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (check(a, n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}