#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    priority_queue<int> PQ;
    for (auto x : mp)
    {
        PQ.push(x.second);
    }
    while (k)
    {

        int temp = PQ.top();
        temp--;
        k--;
        PQ.pop();
        PQ.push(max(temp, 0));
    }
    ll res = 0;
    while (!PQ.empty())
    {
        res += 1ll * PQ.top() * PQ.top();
        PQ.pop();
    }
    cout << res << endl;
    return 0;
}