#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

struct Matrix
{
    ll a[2][2];
    // nạp chồng toán tử dấu nhân
    Matrix operator*(Matrix other)
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] += a[i][k] * other.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    Matrix x;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> x.a[i][j];
        }
    }
    Matrix y;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> y.a[i][j];
        }
    }
    Matrix res = x * y;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}