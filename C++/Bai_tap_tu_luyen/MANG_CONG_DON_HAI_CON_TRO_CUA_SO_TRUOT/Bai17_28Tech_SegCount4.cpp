    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n, s;
        cin >> n >> s;
        int a[n];
        multiset<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long l = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            se.insert(a[i]);
            while (*se.rbegin() - *se.begin() > s)
            {
                se.erase(se.find(a[l]));
                l++;
            }
            ans += i - l + 1;
        }

        cout << ans;
    }