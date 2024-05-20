#include <bits/stdc++.h>
#include <fcntl.h>
#include <io.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

wstring originalText = L"Encrypt and Decrypt ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI by Trần Văn Bằng";
// wstring originalText = L"BẰNG";
map<wchar_t, wint_t> vietnameseAlphabet;
int tableSize = 0;
ll isPrime[1005];
vector<ll> primes;

void init()
{
    for (int i = 2; i < 1005; i++)
    {
        isPrime[i] = 1;
    }
    for (int i = 2; i <= sqrt(1005); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < 1005; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 1005; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

ll inverse_modulo(ll a, ll b)
{
    ll r1 = a, r2 = b;
    ll x1 = 1, x2 = 0;
    ll y1 = 0, y2 = 1;

    while (r2 % r1 != 0)
    {
        ll r = r2 % r1;
        ll q = r2 / r1;
        r2 = r1;
        r1 = r;
        ll x = x2 - q * x1;
        ll y = y2 - q * y1;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if (x1 < 0)
        x1 += b;
    return x1;
}

ll power_modulo(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll x = power_modulo(a, b / 2, c) % c;
    if (b % 2 == 0)
        return (x * x) % c;
    else
        return ((x * x) % c * a % c) % c;
}

pair<pair<ll, ll>, pair<ll, ll>> keyGenerator()
{
    ll p = primes[rand() % 5 + 25];
    ll q = primes[rand() % 5 + 25];
    while (p == q)
    {
        q = primes[rand() % 5 + 25];
    }
    ll n = q * p;
    ll phi = (q - 1) * (p - 1);
    ll e = rand() % 20 + 5;
    e = 65537;
    while (__gcd(e, phi) != 1)
    {
        e = rand() % 20 + 5;
    }
    ll d = inverse_modulo(e, phi);
    return {{e, n}, {d, n}};
}

ll encode(ll n, pair<ll, ll> publicKey)
{
    return power_modulo(n, publicKey.first, publicKey.second);
}

ll decode(ll n, pair<ll, ll> privateKey)
{
    return power_modulo(n, privateKey.first, privateKey.second);
}

vector<ll> encrypt(wstring s, pair<ll, ll> publicKey)
{
    vector<ll> cipherText;
    for (wint_t i = 0; i < s.size(); i++)
    {
        cipherText.push_back(encode(s[i], publicKey));
    }
    return cipherText;
}

wstring decrypt(vector<ll> c, pair<ll, ll> privateKey)
{
    wstring plainText = L"";
    for (wint_t i = 0; i < c.size(); i++)
    {
        plainText += wchar_t(decode(c[i], privateKey));
    }
    return plainText;
}

void RunCode()
{

    wcout << L"Văn bản gốc là: " << originalText << endl;
    int t = 100;
    wcout << L"Nhập testcase: ";
    wcin >> t;
    while (t--)
    {

        wcout << L"---------------------------" << endl;
        pair<pair<ll, ll>, pair<ll, ll>> key = keyGenerator();
        pair<ll, ll> publicKey = key.first;
        pair<ll, ll> privateKey = key.second;
        wcout << L"Khóa công khai là: " << publicKey.first << ", " << publicKey.second << endl;
        wcout << L"Khóa bí mật là: " << privateKey.first << ", " << privateKey.second << endl;

        vector<ll> cipherText = encrypt(originalText, publicKey);
        wcout << L"Văn bản sau khi mã hóa là: ";
        for (auto x : cipherText)
        {
            wcout << x;
        }
        wcout << endl;
        wstring plainText = decrypt(cipherText, privateKey);
        wcout << L"Văn bản sau khi giải mã là: " << plainText << endl;

        if (plainText != originalText)
        {
            wcout << L"fail!!" << endl;
            return;
        }
    }
}

void DebugCode()
{
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    init();
    RunCode();
    // DebugCode();
    return 0;
}
