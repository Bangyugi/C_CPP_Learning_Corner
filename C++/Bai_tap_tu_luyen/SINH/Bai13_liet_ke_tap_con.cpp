#include <bits/stdc++.h>
using namespace std;

bool check1(vector<int> v)
{
    if (v[0] == 8 && v[v.size() - 1] == 6)
    {
        return true;
    }
    return false;
}
bool check2(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1] && v[i] == 8)
        {
            return false;
        }
    }
    return true;
}
bool check3(vector<int> v)
{
    int dem = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 6)
        {
            dem++;
        }
        else
        {
            if (dem > 3)
            {
                return false;
            }
            else
            {
                dem = 0;
            }
        }
    }
    if (dem > 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    vector<vector<int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;
        for (int bit = 0; bit < n; bit++)
        {
            if (i & (1 << bit))
            {
                temp.push_back(6);
            }
            else
            {
                temp.push_back(8);
            }
        }
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        if (check1(x) && check2(x) && check3(x))
        {
            for (auto z : x)
            {
                cout << z;
            }
            cout << endl;
        }
    }
}