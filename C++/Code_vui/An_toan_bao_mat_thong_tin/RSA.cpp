#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

ll isprime[30];

vector<ll> primes;

void eratosthenes()
{
    for (int i = 2; i < 30; i++)
    {
        isprime[i] = 1;
    }
    for (int i = 2; i <= sqrt(30); i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < 30; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 30; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
        }
    }
}

ll UCLN(ll a, ll b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

ll inverseModulo(ll a, ll b)
{
    for (int i = 1; i < b; i++)
    {
        if ((a * i) % b == 1)
        {
            return i;
        }
    }
    return -1;
}

ll powerModulo(ll a, ll b, ll c)
{
    if (b == 1)
    {
        return a;
    }
    ll x = powerModulo(a, b / 2, c) % c;
    if (b % 2 == 0)
        return (x * x) % c;
    else
        return ((x * x) % c * a % c) % c;
}

pair<pair<ll, ll>, pair<ll, ll>> generateKey()
{
    srand(time(NULL));
    ll pindex = rand() % 5 + 5;
    ll qindex = rand() % 5 + 5;
    while (qindex == pindex)
    {
        qindex = rand() % 5 + 5;
    }

    ll p = primes[pindex], q = primes[qindex];
    cout << "\np = " << p;
    cout << "\nq = " << q;
    ll n = (p - 1) * (q - 1);
    ll N = q * p;
    ll e = rand() % 25+5;
    while (UCLN(e,n)!=1)
    {
        e = rand() % 25+5;
    }
    ll d = inverseModulo(e, n);
    return {{e, N}, {d, N}};
}

string encrypt(string s, pair<ll, ll> k)
{
    ll e = k.first;
    ll n = k.second;
    string cipherText = "";
    for (ll i = 0; i < (ll)s.size(); i++)
    {

            ll num = s[i];
            num = powerModulo(num, e, n);
            cipherText += to_string(num) + " ";
        
    }
    return cipherText;
}

string decrypt(string s, pair<ll, ll> k)
{
    ll d = k.first;
    ll n = k.second;
    string plainText = "";
    stringstream ss(s);
    string numStr;
    while (ss >> numStr)
    {
        ll num = stoll(numStr);
        num = powerModulo(num, d, n);
        plainText += char(num);
    }
    return plainText;
}

int main()
{
    string s;
    cout << "Nhap van ban can duoc ma hoa: ";
    getline(cin, s);
    cout << s;
    eratosthenes();
    pair<pair<ll, ll>, pair<ll, ll>> key = generateKey();
    cout << "\nKhoa cong khai: " << key.first.first << ", " << key.first.second;
    cout << "\nkhoa bi mat: " << key.second.first << ", " << key.second.second;
    cout << endl;
    string cipherText = encrypt(s, key.first);
    cout << "\nVan ban sau khi ma hoa la: " << cipherText;
    string plainText = decrypt(cipherText, key.second);
    cout << "\nVan ban sau khi giai ma la: " << plainText;
    return 0;
}