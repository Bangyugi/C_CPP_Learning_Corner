    #include <bits/stdc++.h>
    using namespace std;

    bool check = false;
    int a[10000], b[10000];
    vector<int> v[1000000];
    vector<int> x;

    void khoiTao(int k)
    {
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
        }
    }

    void sinhToHopNguoc(int n, int k)
    {
        int i = k;
        while (i >= 1 && a[i] == n - k + i)
        {
            i--;
        }
        if (i == 0)
        {
            check = true;
        }
        else
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
        }
    }

    int main()
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
            x.push_back(b[i]);
        }
        khoiTao(k);
        int j = 1;
        while (!check)
        {
            for (int i = 1; i <= k; i++)
            {
                v[j].push_back(a[i]);
            }
            j++;
            sinhToHopNguoc(n, k);
        }
        for (int i = j; i >= 1; i--)
        {
            if (v[i] == x)
            {
                cout << j - i << endl;
                return 0;
            }
        }
    }