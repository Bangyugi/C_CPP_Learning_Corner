#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool check = true;
    for (int i = 1; i < s.size(); i++)
    {
        if (abs((s[i] - '0') - (s[i - 1] - '0')) != 1)
        {
            check = false;
        }
    }
    if (check)
        cout << "YES";
    else
        cout << "NO";
}