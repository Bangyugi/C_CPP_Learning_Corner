#include <bits/stdc++.h>
using namespace std;

bool checkThuanNghich(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    if (t==s)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    string s;
    getline(cin, s);
    vector<string> v;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        if(checkThuanNghich(word))
        {
            v.push_back(word);
        }
    }
    sort(v.begin(), v.end());
    for (auto x:v)
    {
        cout << x << " ";
    }
}