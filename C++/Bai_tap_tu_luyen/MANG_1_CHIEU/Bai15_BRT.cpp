#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int MIN = INT_MAX;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = a[i] - a[i - 1];
        if (diff < MIN)
        {
            MIN = diff;
            cnt = 1;
        }
        else if (diff == MIN)
        {
            cnt++;
        }
    }

    cout << MIN << " " << cnt;
    return 0;
}