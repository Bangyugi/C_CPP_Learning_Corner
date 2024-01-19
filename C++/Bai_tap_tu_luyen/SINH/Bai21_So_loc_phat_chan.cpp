#include <bits/stdc++.h>
using namespace std;

void sinh(string &s, bool &final)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8')
    {
        s[i] = '6';
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        s[i] = '8';
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for (int i = 1; i <= 10; i++)
    {
        s = string(i, '6');
        bool final = false;
        while (!final)
        {
            string t = s;
            reverse(t.begin(), t.end());
            v.push_back(s + t);
            sinh(s, final);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}