#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char a[n];
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    auto it1 = mp.begin(), it2 = mp.end();
    it2--;
    cout << (*it1).first << " " << (*it1).second << "\n";
    cout << "\n";
    cout << (*it2).first << " " << (*it2).second << "\n";
    cout << "\n";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << "\n";
    }
    cout << "\n";
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        cout << (*it).first << " " << (*it).second << "\n";
    }
}