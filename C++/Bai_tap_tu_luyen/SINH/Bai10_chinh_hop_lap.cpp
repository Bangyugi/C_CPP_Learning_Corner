#include <bits/stdc++.h>
using namespace std;

int a[100000];
bool check = false;

void init(int k)
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = 1;
    }
}

void sinh(int n, int k)
{
    int i = k;
    while (i >= 1 && a[i] == n)
    {
        i--;
    }
    if (i == 0)
    {
        check = true;
    }
    else
    {
        a[i]++;
        for (int j=i+1;j<=k;j++)
        {
            a[j]=1;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    init(k);
    while (!check)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh(n, k);
    }
}