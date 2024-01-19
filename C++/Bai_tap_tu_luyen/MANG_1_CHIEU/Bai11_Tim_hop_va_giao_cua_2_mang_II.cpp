#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            v1.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            v1.push_back(b[j]);
            j++;
        }
        else
        {
            v2.push_back(a[i]);
            v1.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        v1.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        v1.push_back(b[j]);
        j++;
    }
    for (auto x : v1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : v2)
    {
        cout << x << " ";
    }
}