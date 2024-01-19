#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l] > a[r])
        {
            swap(a[r], a[l]);
        }
        r--;
        l++;
    }
    bool oke = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            oke = false;
            break;
        }
    }
    if (oke)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}