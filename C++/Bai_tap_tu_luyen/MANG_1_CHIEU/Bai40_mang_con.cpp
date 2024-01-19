#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m;i++)
    {
        cin >> b[i];
    }
    int i = 0;
    int j = 0;
    while (i<n && j<m)
    {
        if(b[j]==a[i])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j<m)
    {
        cout << "NO";
    }
    else
        cout << "YES";
}