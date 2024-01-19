#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

struct Matrix
{
    ll a[20][20];
    ll n;
    friend Matrix operator*(Matrix x, Matrix y)
    {
        Matrix res;
        res.n = x.n;
        for (int i = 0; i < x.n; i++)
        {
            for (int j = 0; j < x.n; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < x.n; k++)
                {
                    res.a[i][j] += x.a[i][k] % MOD * y.a[k][j] % MOD;
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix a, ll k)
{
    if (k == 1)
    {
        return a;
    }
    Matrix x = binpow(a, k / 2);
    if (k % 2 == 0)
    {
        return x * x;
    }
    else
    {
        return x * x * a;
    }
}

int main()
{
    ll k;
    Matrix x;
    cin >> x.n >> k;

    for (int i = 0; i < x.n; i++)
    {
        for (int j = 0; j < x.n; j++)
        {
            cin >> x.a[i][j];
        }
    }

    Matrix res = binpow(x, k);

    for (int i = 0; i < x.n; i++)
    {
        for (int j = 0; j < x.n; j++)
        {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}