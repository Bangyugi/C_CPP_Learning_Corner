#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

ll binPow(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll x = binPow(a, b / 2, c) % c;
    if (b % 2 == 0)
        return (x * x) % c;
    else
        return ((x * x) % c * a % c) % c;
}

int main()
{
    ll a, b, c;
    cout << "Tinh a^b mod c = ?" << endl;
    cout << "-----------------------" << endl
        << endl;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;
    cout << "Nhap so nguyen c: ";
    cin >> c;
    cout << "-----------------------" << endl;
    cout << a << "^" << b << " mod " << c << " = " << binPow(a, b, c);
    return 0;
}