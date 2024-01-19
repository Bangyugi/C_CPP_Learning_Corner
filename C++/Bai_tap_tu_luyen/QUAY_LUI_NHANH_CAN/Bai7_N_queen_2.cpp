#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005][1005];
int cot[1005];
int duongcheonguoc[1005];
int duongcheoxuoi[1005];
int cnt = 0;
int ans = 0;
int X[1005];

void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 0 && duongcheonguoc[i + j - 1] == 0 && duongcheoxuoi[i - j + n] == 0)
        {
            cnt += a[i][j];
            cot[j] = duongcheoxuoi[i - j + n] = duongcheonguoc[i + j - 1] = 1;
            if (i == 8)
            {
                ans = max(ans, cnt);
            }
            else
            {
                Try(i + 1, n);
            }
            cnt -= a[i][j];
            cot[j] = duongcheoxuoi[i - j + n] = duongcheonguoc[i + j - 1] = 0;
        }
    }
}

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 8);
    cout << ans;
    return 0;
}