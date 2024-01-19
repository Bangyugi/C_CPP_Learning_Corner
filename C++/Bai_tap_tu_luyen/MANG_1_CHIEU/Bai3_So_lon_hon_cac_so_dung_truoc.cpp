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
    int MAX = INT_MIN;
    for (int i = 0; i < n;i++)
    {
        if (a[i]>MAX)
        {
            MAX = a[i];
            cout << a[i] << " ";
        }
    }
}