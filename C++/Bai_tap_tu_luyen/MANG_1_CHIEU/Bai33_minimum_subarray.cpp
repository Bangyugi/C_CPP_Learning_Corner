#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int length = INT_MAX;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        int sum = a[i];
        int cnt = 1;
        for (int j = i + 1; sum < k; j++)
        {
            sum += a[j];
            cnt++;
        }
        if (sum == k)
        {
            length = min(length, cnt);
            check = true;
        }
    }
    if (check)
        cout << length;
    else
        cout << -1;
}