#include <bits/stdc++.h>
using namespace std;

int *p = new int[10000005];

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
        if (b[j] > max_val)
        {
            max_val = b[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (*(p + a[i]) == 0)
        {
            *(p + a[i]) += 1;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (*(p + b[j]) <= 1)
        {
            *(p + b[j]) += 1;
        }
    }
    cout << "\nHop: ";
    for (int i = 0; i <= max_val; i++)
    {
        if (*(p + i) != 0)
        {
            cout << i << " ";
        }
    }
    cout << "\nGiao: ";
    for (int i = 0; i <= max_val; i++)
    {
        if (*(p + i) == 2)
        {
            cout << i << " ";
        }
    }
}