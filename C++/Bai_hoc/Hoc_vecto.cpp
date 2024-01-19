#include <bits/stdc++.h>
using namespace std;
int cnt1[10000001], cnt2[10000001];
typedef long long ll;
const int MOD = 1e9 + 7;

void vectorCoBan(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    v.insert(v.begin() + 2, 1000);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    v.erase(v.begin() + 4);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    v.resize(5);
    for (auto x : v)
    {
        cout << x << " ";
    }
}

void timKiemPhanTu(vector<int> v)
{
    int target = 5;
    // Tìm kiếm phần tử target trong vecto
    bool found = binary_search(v.begin(), v.end(), target);
    if (found)
    {
        cout << "FOUND\n";
    }
    else
    {
        cout << "NOT FOUND\n";
    }
}

void timGiaTriLonNhat(vector<int> v)
{
    auto max_val = max_element(v.begin(), v.end());
    cout << "\nGia tri lon nhat trong vector la: " << max_val;
    cout << "\nVi tri lon nhat trong vector la: " << distance(v.begin(), max_val);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vectorCoBan(v);
    timKiemPhanTu(v);
    timGiaTriLonNhat(v);
}