#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ll tu, mau;
    cin >> tu >> mau;
    while (1)
    {
        if (mau % tu == 0)
        {
            cout << 1 << "/" << mau / tu;
            break;
        }
        else
        {
            ll X = mau / tu + 1;
            cout << 1 << "/" << X << " + ";
            tu = tu * X - mau;
            mau = mau * X;
        }
    }

    return 0;
}
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll MOD = 1e9 + 7;

// ll gcd(ll a, ll b)
// {
//     while (b)
//     {
//         ll t = a % b;
//         a = b;
//         b = t;
//     }
//     return a;
// }

// struct phanSo
// {
//     ll tu, mau;

//     void rutGon()
//     {
//         ll k = gcd(tu, mau);
//         tu /= k;
//         mau /= k;
//     }

//     phanSo operator-(phanSo b)
//     {
//         ll mauRes = this->mau * b.mau;
//         ll tuRes = this->tu * b.mau - this->mau * b.tu;
//         phanSo res = phanSo{tuRes, mauRes};
//         res.rutGon();
//         return res;
//     }
// };

// int main()
// {
//     ll tu, mau;
//     cin >> tu >> mau;
//     phanSo p = phanSo{tu, mau};
//     while (p.tu != 0)
//     {
//         ll x = (p.mau + p.tu - 1) / p.tu;
//         phanSo tmp = phanSo{1, x};
//         cout << 1 << "/" << x;
//         p = p - tmp;
//         if (p.tu != 0)
//             cout << " + ";
//     }

//     return 0;
// }