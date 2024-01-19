#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005][1005];
int cot[1005];
int duongcheonguoc[1005];
int duongcheoxuoi[1005];
int cnt = 0;
int X[1005];

void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 0 && duongcheoxuoi[i - j + n] == 0 && duongcheonguoc[i + j - 1] == 0)
        {
            cot[j] = duongcheoxuoi[i - j + n] = duongcheonguoc[i + j - 1] = 1;
            if (i == n)
            {
                cnt++;
            }
            else
            {
                Try(i + 1, n);
            }
            cot[j] = duongcheoxuoi[i - j + n] = duongcheonguoc[i + j - 1] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Try(1, n);
    cout << cnt;
    return 0;
}