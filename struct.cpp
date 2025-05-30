#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct Quat
{
    string hang;
    string mausac;
    int giaban;
};

bool soSanhGia(const Quat &a, const Quat &b)
{
    return a.giaban < b.giaban;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int p = 500000;

    vector<Quat> danhSach = {
        {"Panasonic", "Trắng", 300000},
        {"Asia", "Xanh", 200000},
        {"Senko", "Đỏ", 250000},
        {"Midea", "Xám", 150000},
        {"Toshiba", "Đen", 400000},
        {"Sharp", "Xanh dương", 100000},
        {"LG", "Trắng", 350000},
        {"Samsung", "Xanh lá", 450000}};

    int n = danhSach.size();
    int tongTien = 0;
    vector<Quat> dsMua;

    sort(danhSach.begin(), danhSach.end(), soSanhGia);

    for (int i = 0; i < n; ++i)
    {
        if (tongTien + danhSach[i].giaban <= p)
        {
            dsMua.push_back(danhSach[i]);
            tongTien += danhSach[i].giaban;
        }
        else
        {
            break;
        }
    }

    // In kết quả
    cout << "So tien ban dau: " << p << " VND" << endl;
    cout << "Co the mua " << dsMua.size() << " chiec quat ban:\n";

    for (const auto &q : dsMua)
    {
        cout << " - Hang: " << q.hang << ", Gia ban: " << q.giaban << " VND" << endl;
    }

    cout << "Tong tien da su dung: " << tongTien << " VND" << endl;

    return 0;
}
