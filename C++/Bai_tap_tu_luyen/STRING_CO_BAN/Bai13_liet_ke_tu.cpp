#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (!isalpha(s[i]))
        {
            s[i] = ' ';
        }
    }
    // cout << s << endl;
    stringstream ss(s);
    string t;
    string word;
    while (ss >> word)
    {
        if (t.size() == 0)
        {
            t += word;
        }
        else
        {
            t = t + " " + word;
        }
    }
    cout << t;
}