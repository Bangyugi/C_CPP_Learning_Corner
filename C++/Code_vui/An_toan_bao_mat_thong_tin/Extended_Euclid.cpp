#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

ll Extended_Euculid(ll a, ll b)
{
    ll r1 = a, r2 = b;
    ll x1 = 1, x2 = 0;
    ll y1 = 0, y2 = 1;

    while (r2 % r1 != 0)
    {
        ll r = r2 % r1;
        ll q = r2 / r1;
        ll x = x2 - q * x1;
        ll y = y2 - q * y1;
        r2 = r1;
        r1 = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if (x1 < 0)
    {
        return b + x1;
    }
    return x1;
}

int main()
{
    ll a, b;
    cout << "Tinh a^-1 mod b = ?" << endl;
    cout << "-----------------------" << endl
        << endl;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;
    if (GCD(a, b) != 1)
    {
        cout << "Khong ton tai nghich dao cua " << a << " mod " << b << "!";
        return 0;
    }
    cout << "Nghich dao cua " << a << " mod " << b << " la: " << Extended_Euculid(a, b);
    return 0;
}