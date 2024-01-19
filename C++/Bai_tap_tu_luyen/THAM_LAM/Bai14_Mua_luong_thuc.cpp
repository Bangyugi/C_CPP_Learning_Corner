#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int N, S, M;
    cin >> N >> S >> M;
    // Nếu lương thực mua trong S ngày trừ ngày chủ nhật < số lương 
    //thực cần cho S ngày => không đủ sống
    if (N * (S - S / 7) < M * S)
    {
        cout << -1;
    }
    else
    {
        // Kiểm tra tới bao giờ thi mua đủ số lương thực cần cho S ngày
        for (int i = 1; i <= S - S / 7; i++)
        {
            if (N * i >= M * S)
            {
                cout << i;
                return 0;
            }
        }
        cout << -1;
    }
    return 0;
}