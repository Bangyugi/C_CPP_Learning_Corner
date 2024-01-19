#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cnt = 0;
vector<ll> v;
ll sum = 0;
int used[1001];

void Try(int i, int a[], int n, int s, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        // if (used[a[j]] == 0)
        {
            sum += a[j];
            v.push_back(a[j]);
            if (sum == s)
            {
                cnt++;
                for (auto x : v)
                {
                    used[x] = cnt;
                    // cout << x << " ";
                }
                // cout << endl;
            }
            else
            {
                Try(i + 1, a, n, s, j + 1);
            }
            sum -= a[j];
            v.pop_back();
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    sort(a + 1, a + n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if (tong % k != 0)
    {
        cout << 0;
    }
    else
    {
        int s = tong / k;
        Try(1, a, n, s, 1);
        if (cnt == k)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    // cout << cnt << endl;
}