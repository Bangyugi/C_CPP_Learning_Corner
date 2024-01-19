#include <bits/stdc++.h>
using namespace std;

bool check1(vector<int> v, int k)
{
    int dem = 0;
    for (int x : v)
    {
        if (x == 1)
        {
            dem++;
        }
    }
    return dem == k;
}

bool check2(vector<int> v, int k)
{
    int cum = 0, dem = 0;
    for (auto x : v)
    {
        if (x == 1)
            dem++;
        else
        {
            if (dem == k)
                cum++;
            dem = 0;
        }
        if (dem > k)
            return false;
    }
    if (dem == k)
        cum++;
    return cum == 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> l;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> v;
        int dem = 0;
        for (int bit = n - 1; bit >= 0; bit--)
        {
            if (i & (1 << bit))
            {
                v.push_back(1);
                dem++;
            }
            else
            {
                v.push_back(0);
            }
        }
        l.push_back(v);
    }
    for (auto x : l)
    {
        if (check1(x, k))
        {
            for (auto z : x)
            {
                cout << z;
            }
            cout << " ";
        }
    }
    cout << endl;
    for (auto x : l)
    {
        if (check2(x, k))
        {
            for (auto z : x)
            {
                cout << z;
            }
            cout << " ";
        }
    }
}