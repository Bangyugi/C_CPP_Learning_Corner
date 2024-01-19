#include <bits/stdc++.h>
using namespace std;

vector<char> Board[10] = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
// string temp;
vector<string> v;

void Lmao(int i, string s, string &temp)
{
    int n = Board[s[i] - '0'].size();
    // cout<<n;
    // cout << s[i] << " " << Board[s[i]-'0'].size();
    for (int j = 0; j < n; j++)
    {
        temp.push_back(Board[s[i] - '0'][j]);
        if (temp.size() == s.size())
        {
            // cout << temp << " ";
            v.push_back(temp);
        }
        else if (i < s.size())
        {
            Lmao(i + 1, s, temp);
        }
        temp.pop_back();
    }
}

int main()
{
    string s;
    string temp;
    cin >> s;
    sort(s.begin(), s.end());
    Lmao(0, s, temp);
    for (auto x : v)
    {
        cout << x << ' ';
    }
}