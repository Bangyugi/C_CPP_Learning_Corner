#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define MAX 100005;
using namespace std;
ll MOD = 1e9 + 7;

struct Good
{
    int id;
    char tenHang[30];
    char tenNhaSanXuat[30];
    int namSanXuat;
    int giaBan;
};

void input(Good &x)
{
    cout << "Nhap id: ";
    cin >> x.id;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    cin.getline(x.tenHang, 30);
    cout << "Nhap ten nha san xuat: ";
    cin.getline(x.tenNhaSanXuat, 30);
    cout << "Nhap nam san xuat: ";
    cin >> x.namSanXuat;
    cout << "Nhap gia ban: ";
    cin >> x.giaBan;
    cin.ignore();
}

void output(Good x)
{
    cout << "Id: " << x.id << endl;
    cout << "Ten san pham: " << x.tenHang << endl;
    cout << "Ten nha san xuat: " << x.tenNhaSanXuat << endl;
    cout << "Nam san xuat: " << x.namSanXuat << endl;
    cout << "Gia ban: " << x.giaBan << endl;
    cout << endl;
}

struct L
{
    int count;
    Good e[10005];
};

void themCuoi(L &iPad, Good x)
{
    iPad.count++;
    iPad.e[iPad.count] = x;
}

void themGiua(L &iPad, Good x, int k)
{
    iPad.count++;
    for (int i = iPad.count; i >= k; i--)
    {
        iPad.e[i] = iPad.e[i - 1];
    }
    iPad.e[k] = x;
}

void xoaGiua(L &iPad, int k)
{
    iPad.count--;
    for (int i = k; i <= iPad.count; i++)
    {
        iPad.e[i] = iPad.e[i + 1];
    }
}

void xoa1998(L &iPad)
{
    for (int i = 1; i <= iPad.count;)
    {
        if (iPad.e[i].namSanXuat == 1998)
        {
            for (int j = i; j < iPad.count; j++)
            {
                iPad.e[j] = iPad.e[j + 1];
            }
                iPad.count--;
        }
        else
        {
            i++;
        }
    }
}

void display(L iPad)
{
    for (int i = 1; i <= iPad.count; i++)
    {
        output(iPad.e[i]);
    }
}

int main()
{
    L iPad;
    iPad.count = 0;
    for (int i = 0; i < 5; i++)
    {
        Good x;
        input(x);
        themCuoi(iPad, x);
    }
    // display(iPad);
    // Good x;
    // input(x);
    int k;
    // cout << "Nhap vi tri muon chen: ";
    // cin >> k;
    // cin.ignore();
    // themGiua(iPad, x, k);
    // display(iPad);
    // cout << "Nhap vi tri muon xoa: ";
    // cin >> k;
    // cin.ignore();
    // xoaGiua(iPad, k);
    // display(iPad);
    cout << "Xoa 1998:\n";
    xoa1998(iPad);
    display(iPad);
    return 0;
}
