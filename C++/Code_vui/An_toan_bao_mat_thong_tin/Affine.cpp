#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

vector<ll> coprime;

ll UCLN(ll a, ll b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

ll mod(ll a, ll b)
{
    for (int i = 1; i < b; i++)
    {
        if ((i * a) % b == 1)
            return i;
    }
    return -1;
}

void key(ll &a, ll &b)
{
    srand(time(NULL));
    for (ll i = 2; i < 26; i++)
    {
        if (UCLN(i, 26) == 1)
        {
            coprime.push_back(i);
        }
    }
    a = coprime[rand() % coprime.size()];
    b = rand() % 26;
    cout << "\nKhoa K: K{(" << a << "," << b << ")} ";
}

string encrypt(string s, ll a, ll b)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
            if (isupper(s[i]))
                s[i] = (char)((a * (s[i] - 'A') + b) % 26 + 'A');
            else
                s[i] = (char)((a * (s[i] - 'a') + b) % 26 + 'a');
    }
    return s;
}

string decrypt(string s, ll a, ll b)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                ll temp = (s[i] - 'A' - b) % 26;
                if (temp < 0)
                {
                    temp += 26;
                }
                s[i] = ((mod(a, 26) * temp) % 26) + 'A';
            }
            else
            {
                ll temp = (s[i] - 'a' - b) % 26;
                if (temp < 0)
                {
                    temp += 26;
                }
                s[i] = ((mod(a, 26) * temp) % 26) + 'a';
            }
        }
    }
    return s;
}

int main()
{
    string s;
    cout << "Nhap van ban can ma hoa: ";
    getline(cin, s);
    cout << s;
    ll a, b;
    key(a, b);
    string cipherText = encrypt(s, a, b);
    string plainText = decrypt(cipherText, a, b);

    cout << "\nVan ban sau khi ma hoa la: " << cipherText;
    cout << "\nVan ban sau khi giai ma la: " << plainText;
    return 0;
}