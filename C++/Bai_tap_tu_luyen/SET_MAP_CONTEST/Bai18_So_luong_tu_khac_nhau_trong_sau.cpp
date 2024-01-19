#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    set<string> se;
    while (cin >> s)
    {
        se.insert(s);
    }
    cout << se.size() << "\n";
    auto it1 = se.begin();
    auto it2 = se.end();
    it2--;
    cout << *it1 << " " << *it2;
}