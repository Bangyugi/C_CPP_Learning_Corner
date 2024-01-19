#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
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
        v.push_back(word);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
    {
        cout << x << " ";
    }
}