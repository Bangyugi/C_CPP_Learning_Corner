#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string t;

void Try(int n, int k, string s, int i, int pos)
{
    for (int j = pos; j < n; j++)
    {
        t.push_back(s[j]);
        if (i == k - 1)
        {
            v.push_back(t);
        }
        else
        {
            Try(n, k, s, i + 1, j);
        }
        t.pop_back();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    Try(n, k, s, 0, 0);
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << "\n";
    }
}