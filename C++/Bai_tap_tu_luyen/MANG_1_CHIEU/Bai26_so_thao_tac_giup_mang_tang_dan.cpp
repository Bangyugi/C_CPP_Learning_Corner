#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            long long temp = a[i - 1] - a[i] + 1;
            cnt += temp;
            a[i] += temp;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    cout << cnt;
}