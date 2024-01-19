#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int max_char = INT_MIN, min_char = INT_MAX;
    char char_value;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second > max_char)
        {
            max_char = (*it).second;
            char_value = (*it).first;
        }
    }
    cout << char_value << " " << max_char << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second <= min_char)
        {
            min_char = (*it).second;
            char_value = (*it).first;
        }
    }
    cout << char_value << " " << min_char << endl;
    cout << mp.size();
}