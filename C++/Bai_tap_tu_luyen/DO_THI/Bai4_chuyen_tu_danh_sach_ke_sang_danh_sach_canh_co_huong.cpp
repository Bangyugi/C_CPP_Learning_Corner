#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> edge;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string number;
        while (ss >> number)
        {
            edge.push_back({i, stoi(number)});
        }
    }
    sort(edge.begin(),edge.end());
    for (auto x : edge)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}