#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)

int main()
{
    string s;
    cin >> s;
    int a[12];
    set<char> se;
    for (int i = 0; i < s.size(); i++)
    {
        se.insert(s[i]);
    }
    vector<char> v;
    for (auto x : se)
    {
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
    {
        a[i] = i;
    }
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[a[i]];
        }
        cout << endl;
    } while (next_permutation(a, a + v.size()));
}