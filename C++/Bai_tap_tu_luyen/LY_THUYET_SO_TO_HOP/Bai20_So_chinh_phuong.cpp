#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long temp = sqrt(n);
    if (temp * temp == n)
        cout << "YES";
    else
        cout << "NO";
}