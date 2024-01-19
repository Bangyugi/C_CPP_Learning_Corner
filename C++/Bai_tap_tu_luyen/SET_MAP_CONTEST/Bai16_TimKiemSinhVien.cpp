#include <bits/stdc++.h>
using namespace std;

int main()
{
    string msv;
    string name;
    map<string, string> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> msv;
        cin.ignore();
        getline(cin, name);
        mp.insert({msv, name});
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> msv;
        auto it = mp.find(msv);
        if (it != mp.end())
        {
            cout << (*it).second << endl;
        }
        else
        {
            cout << "NOT FOUND\n";
        }
    }
}