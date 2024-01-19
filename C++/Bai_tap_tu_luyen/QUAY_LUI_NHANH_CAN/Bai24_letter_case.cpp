#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> v;
vector<int> t;
set<string> se;
int x[1000];

void makeLower(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }
}

void sinhNhiPhan(int i, int n)
{
    for (int j = 0; j <= 1; j++)
    {
        t.push_back(j);
        if (i == n)
        {
            v.push_back(t);
        }
        else
        {
            sinhNhiPhan(i + 1, n);
        }
        t.pop_back();
    }
}

void solve(string s, vector<int> v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            if (v[i])
            {
                s[i] = toupper(s[i]);
            }
        }
    }
    se.insert(s);
}

int main()
{
    string s;
    cin >> s;
    makeLower(s);
    int n = (int)s.size();
    sinhNhiPhan(1, n);
    for (auto x : v)
    {
        solve(s, x, n);
    }
    for (auto x : se)
    {
        cout << x << endl;
    }
    return 0;
}
