#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tong = 0;
int X[1000];
bool check = false;

void backtrack(int i, int pos, int n, int a[], int s)
{
    for (int j = pos; j <= n; j++)
    {
        tong += a[j];
        X[i] = a[j];
        if (tong == s)
        {
            check = true;
        }
        else if (tong < s)
        {
            backtrack(i + 1, j + 1, n, a, s);
        }
        tong -= a[j];
        X[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    else
    {
        int s = sum / 2;
        backtrack(1, 1, n, a, s);
        if (check)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}