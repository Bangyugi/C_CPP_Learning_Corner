#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
using namespace std;
vector<wchar_t> vietnameseAlphabet;

wstring encrypt(wstring s, wint_t k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        s[i] = ((wint_t)s[i] + k) % 7929;
    }
    return s;
}

wstring decrypt(wstring s, wint_t k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        s[i] = ((wint_t)s[i] - k) % 7929;
    }
    return s;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    // alphabet();
    // for (auto ch : vietnameseAlphabet)
    // {
    //     wcout << ch << L" : " << int(ch) << L"\n";
    // }
    wcout << L"Nhập số testcase: ";
    wint_t t;
    wcin >> t;
    while (t--)
    {
        wcout << "\n ------------------------------- \n\n";
        wstring originalText = L"Bằng Trần Văn Đẹp Trai, ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI";
        // wcout << L"Nhập vào văn bản cần mã hóa: ";
        // wcin >> originalText;
        // for (wint_t i = 0; i < (wint_t)originalText.size(); i++)
        // {
        //     wcout << originalText[i] << " : " << (wint_t)originalText[i] << endl;
        // }
        wint_t k = rand() % 25 + 1;
        wcout << L"Khóa K là: " << k << endl;
        wstring cipherText = encrypt(originalText, k);
        wcout << L"Văn bản sau khi mã hóa là: " << cipherText << endl;
        wstring plainText = decrypt(cipherText, k);
        wcout << L"Văn bản sau khi giải mã là: " << plainText << endl;
        if (plainText != originalText)
        {
            wcout << L"fail!!" << endl;
            return 0;
        }
    }
    return 0;
}