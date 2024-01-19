#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    map<string, multiset<string>> mps;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string teamI, teamII, word;
        string *temp = &teamI;
        while (ss >> word)
        {
            if (word == "-")
            {
                temp = &teamII;
                continue;
            }
            else
            {
                if ((*temp).size() != 0)
                    *temp = *temp + " " + word;
                else
                    *temp = *temp + word;
            }
        }
        mps[teamI].insert(teamII);
        mps[teamII].insert(teamI);
    }
    for (auto x : mps)
    {
        cout << x.first << " : ";
        for (auto it = (x.second).begin(); it != (x.second).end(); it++)
        {
            if (it != (x.second).begin())
                cout << ", " << *it;
            else
                cout << *it;
        }
        cout << endl;
    }
}