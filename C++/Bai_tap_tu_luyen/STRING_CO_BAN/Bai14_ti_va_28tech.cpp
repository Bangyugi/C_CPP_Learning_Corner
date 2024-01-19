#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    long long cnt = 0;
    stringstream ss(s);
    string word;
    string t = "28tech";
    // cout << s << endl;
    while (ss >> word)
    {
        if (word == t)
        {
            cnt++;
        }
    }
    cout << cnt;
}