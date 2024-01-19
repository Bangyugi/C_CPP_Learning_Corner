#include <bits/stdc++.h>
using namespace std;

int n, cnt, final = 0;
int a[1000001];
vector<vector<int>> v;

void khoiTao()
{
    cnt = 1;
    a[1] = n;
}

void sinh()
{
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i], r = d % a[i];
        if (q > 0)
        {
            for (int j = 1; j <= q; j++)
            {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if (r > 0)
        {
            cnt++;
            a[cnt] = r;
        }
    }
}

int main()
{
    cin >> n;
    khoiTao();
    while (!final)
    {
        vector<int> temp;
        for (int i = 1; i <= cnt; i++)
        {
            temp.push_back(a[i]);
        }
        v.push_back(temp);
        sinh();
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            cout << "+" << v[i][j];
        }
        cout << endl;
    }
}