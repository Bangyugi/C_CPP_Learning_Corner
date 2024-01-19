#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    // cout << s << endl;
    stringstream ss(s);
    string t;
    string word;
    int cnt = 0;
    while (ss >> word)
    {
        if (cnt%2==1)
        {
            reverse(word.begin(), word.end());
        }
        if (t.size() == 0)
        {
            t += word;
        }
        else
        {
            t = t + " " + word;
        }
        cnt++;
    }
    cout << t;
}