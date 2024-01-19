#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (auto x : s)
    {
        v.push_back(x);
    }
    // int a[10002];
    if (next_permutation(v.begin(), v.end()))
    {
        // next_permutation(a, a + v.size());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
    }
    else
    {
        cout << "NOT EXIST";
    }
    cout << endl;
}