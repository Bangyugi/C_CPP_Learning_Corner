#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll fibo[100];

struct Matrix
{
    ll a[100][100];
    friend Matrix operator*(Matrix x, Matrix y)
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] += x.a[i][k] % MOD * y.a[k][j] % MOD;
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix a, ll n)
{
    if (n == 1)
    {
        return a;
    }
    Matrix x = binpow(a, n / 2);
    if (n % 2 == 0)
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

    ll n;
    cin >> n;
    Matrix x;
    x.a[0][0] = x.a[1][0] = x.a[0][1] = 1;
    x.a[1][1] = 0;
    Matrix res = binpow(x, n);
    cout << res.a[1][0] << endl;
}