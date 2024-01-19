#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    map<string, pair<int, int>> mp;
    while (getline(cin, s))
    {
        
        stringstream ss(s);
        string lmao;
        while (ss >> lmao)
        {
            v.push_back(lmao);
        }
        // cout << v[0] << " " << stoi(v[1]) << " " << stoi(v[2]) << "\n";
        if (!mp.count(v[0]))
        {
            mp[v[0]].first = stoi(v[2]) * stoi(v[1]);
            mp[v[0]].second = stoi(v[1]);
        }
        else
        {
            mp[v[0]].first = mp[v[0]].first + stoi(v[1]) * stoi(v[2]);
            mp[v[0]].second = mp[v[0]].second + stoi(v[1]);
        }
        v.clear();
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        cout << (*it).first << " : " << fixed << setprecision(2) << (double)(((*it).second).first) / ((*it).second).second << endl;
    }
}