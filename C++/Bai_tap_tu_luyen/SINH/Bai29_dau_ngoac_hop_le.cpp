#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (v.empty())
            {
                return false;
            }
            else
                v.pop_back();
        }
        else
        {
            v.push_back('(');
        }
    }
    if (v.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sinh(string &s, bool &final)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ')')
    {
        s[i] = '(';
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        s[i] = ')';
    }
}

int main()
{
    vector<string> v;
    int n;
    cin >> n;
    string s;
    s = string(n, '(');
    bool final = false;
    while (!final)
    {
        if (check(s))
        {
            v.push_back(s);
        }
        sinh(s, final);
    }
    if (v.empty())
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        for (auto x : v)
        {
            cout << x << endl;
        }
    }
}