#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int a, b, c, d;
    cout << "Nhap muc luong theo h: ";
    cin >> a;
    cout << "Nhap so gio lam viec: ";
    cin >> b;
    cout << "Nhap so tien thuong: ";
    cin >> c;
    cout << "Nhap so tien phat: ";
    cin >> d;
    cout << "Thuc linh = " << a * b + c - d;
}