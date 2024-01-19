#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long temp = sqrt(n);
    if (n / temp == sqrt(n))
        cout << "YES";
    else
        cout << "NO";
}