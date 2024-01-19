#include <bits/stdc++.h>
using namespace std;

int used[25];
int cnt = 0;
int sum = 0;
int X[100];

void backTrack(int i, int n, int k, int s)
{
    for (int j = X[i - 1] + 1; j <= n; j++)
    {
        if (!used[j])
        {
            sum += j;
            used[j] = 1;
            X[i] = j;
            if (i == k)
            {
                if (sum == s)
                {
                    cnt++;
                }
            }
            else
            {
                backTrack(i + 1, n, k, s);
            }
            used[j] = 0;
            sum -= j;
        }
    }
}

int main()
{
    int n, k, s;
    cin >> n >> k >> s;
    backTrack(1, n, k, s);
    cout << cnt << endl;
}