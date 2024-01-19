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
    set<int> se;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            cout << 1;
            return 0;
        }
        if (se.count(sum))
        {
            cout << 1;
            return 0;
        }
        se.insert(sum);
    }
    cout << -1;
    return 0;
}