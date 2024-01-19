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
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    cout << "Tong: " << a + b;
    cout << "\nHieu: " << a - b;
    cout << "\nTich: " << a * b;
    cout << "\nThuong: " << a * 1.0 / b;
    return 0;
}