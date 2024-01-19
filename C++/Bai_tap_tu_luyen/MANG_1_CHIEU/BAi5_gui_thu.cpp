#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int mini;
    int maxi;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mini = a[1] - a[0];
            maxi = a[n - 1] - a[0];
        }
        else if (i == n - 1)
        {
            mini = a[i] - a[i - 1];
            maxi = a[i] - a[0];
        }
        else
        {
            mini = min(a[i] - a[i - 1], a[i + 1] - a[i]);
            maxi = max(a[i] - a[0], a[n - 1] - a[i]);
        }
        cout << mini << " " << maxi << endl;
    }
}