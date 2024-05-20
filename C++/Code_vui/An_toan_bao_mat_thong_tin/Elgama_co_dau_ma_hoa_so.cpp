#include <bits/stdc++.h>
#include <fcntl.h>
#include <io.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

wstring originalText = L"Encrypt and Decrypt ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI by Trần Văn Bằng";
int isPrime[10005];
vector<int> primes;


void init()
{
    for (int i = 2; i < 10005; i++)
    {
        isPrime[i] = 1;
    }
    for (int i = 2; i <= sqrt(10005); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < 10005; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 10005; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

struct Key
{
    ll first, second, third;
    wstring toString()
    {
        return L"{" + to_wstring(first) + L", " + to_wstring(second) + L", " + to_wstring(third) + L"}";
    }
};

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

ll inverse_modulo(ll a, ll b)
{
    ll r1 = a, r2 = b;
    ll x1 = 1, x2 = 0;
    ll y1 = 0, y2 = 1;
    while (r2 % r1 != 0)
    {
        ll r = r2 % r1;
        ll q = r2 / r1;
        ll x = x2 - q * x1;
        ll y = y2 - q * y1;
        r2 = r1;
        r1 = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if (x1 < 0)
        x1 += b;
    return x1;
}

pair<Key, Key> generateKey()
{
    ll p = primes[rand() % 20 + 1200];

    ll a = rand() % 20 + 50;
    while (a == p)
        a = rand() % 20 + 50;

    ll x = rand() % 20 + 50;
    while (x == a)
        x = rand() % 20 + 50;
    while (x == p)
        x = rand() % 20 + 50;

    ll y = power_modulo(a, x, p);
    return {{p, a, y}, {p, a, x}};
}

pair<ll, ll> encode(ll number, Key publicKey)
{
    ll k = rand() % 20 + 50;
    ll K = power_modulo(publicKey.third, k, publicKey.first);
    return {power_modulo(publicKey.second, k, publicKey.first), K * number % publicKey.first};
}

ll decode(pair<ll, ll> C, Key privateKey)
{
    ll K = power_modulo(C.first, privateKey.third, privateKey.first);
    return ((C.second % privateKey.first) * inverse_modulo(K, privateKey.first)) % privateKey.first;
}

vector<pair<ll, ll>> encrypt(wstring s, Key publicKey)
{
    vector<pair<ll, ll>> cipherText;
    for (wint_t i = 0; i < s.size(); i++)
    {
        pair<ll, ll> x = encode(s[i], publicKey);
        cipherText.push_back({x.first, x.second});
    }
    return cipherText;
}

wstring decrypt(vector<pair<ll, ll>> cipherText, Key privateKey)
{
    wstring plainText = L"";
    for (wint_t i = 0; i < cipherText.size(); i++)
    {
        plainText += wchar_t(decode({cipherText[i].first, cipherText[i].second}, privateKey));
    }
    return plainText;
}

void runCode()
{
    wcout << L"Văn bản gốc là: " + originalText << endl;
    pair<Key, Key> key = generateKey();
    Key publicKey = key.first;
    Key privateKey = key.second;
    wcout << L"Khóa công khai là: " << publicKey.toString() << endl;
    wcout << L"Khóa bí mật là: " << privateKey.toString() << endl;
    vector<pair<ll, ll>> cipherText = encrypt(originalText, publicKey);
    wcout << L"Văn bản sau khi được mã hóa là: " << endl;
    wcout << L"Cipher Text 1: ";
    for (auto x : cipherText)
    {
        wcout << x.first;
    }
    wcout << endl;
    wcout << L"Cipher Text 2: ";
    for (auto x : cipherText)
    {
        wcout << x.second;
    }
    wcout << endl;
    wstring plainText = decrypt(cipherText,privateKey);
    wcout << L"Văn bản sau khi được giải mã là: " << plainText << endl;
}
void debugCode()
{
    pair<Key, Key> key = generateKey();
    Key publicKey = key.first;
    Key privateKey = key.second;
    wcout << L"Khóa công khai là: " << publicKey.toString() << endl;
    wcout << L"Khóa bí mật là: " << privateKey.toString() << endl;

    ll M = 15;
    wcout << L"Văn bản gốc là: " << M << endl;
    pair<ll, ll> cipherText = encode(M, publicKey);
    wcout << L"Văn bản sau khi mã hóa là: " << cipherText.first << ", " << cipherText.second << endl;
    ll plainText = decode(cipherText, privateKey);
    wcout << L"Văn bản sau khi giải mã là: " << plainText << endl;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    init();
    int t;
    wcout<<L"Nhập số test case: ";
    wcin>>t;
    while(t--){
    runCode();
    //debugCode();
    wcout << "\n-----------------------\n\n";
    }
    return 0;
}
