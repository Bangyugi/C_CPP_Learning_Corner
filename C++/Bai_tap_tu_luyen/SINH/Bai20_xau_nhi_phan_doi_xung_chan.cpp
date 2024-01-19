#include <bits/stdc++.h>
using namespace std;

void sinh(string &s, bool &final)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i < 0)
    {
        final = true;
    }
    else
    {
        s[i] = '1';
    }
}

int main()
{
    int l;
    string s;
    vector<string> v;
    cin >> l;
    for (int i = 1; i <= 15; i++)
    {
        bool final = false;
        s = string(i, '0');
        while (!final)
        {

            string t = s;
            reverse(t.begin(), t.end());
            // s = s + t;
            v.push_back(s + t);
            sinh(s, final);
        }
    }
    sort(v.begin(), v.end());

    for (auto x : v)
    {
        if (x.size() <= l)
        {
            cout << x << endl;
        }
    }
}