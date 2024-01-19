    #include <bits/stdc++.h>
    #define ll long long
    #define ii pair<int, int>
    using namespace std;
    ll MOD = 1e9 + 7;

    vector<int> matrix[100005];
    
    int main()
    {
        // ios_base::sync_with_stdio(NULL);
        // cin.tie(0);
        // cout.tie(0);
        int n, m;
        cin >> n;
        vector<vector<int>> v2(n);
        for (int i = 0; i < n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                v2[i].push_back(j);
            }
        }
        for (int i = 0; i < n;i++)
        {
            for (auto j: v2[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
        return 0;
    }