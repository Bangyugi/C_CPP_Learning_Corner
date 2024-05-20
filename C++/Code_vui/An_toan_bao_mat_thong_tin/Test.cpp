#include <iostream>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
    // Thiết lập locale cho C++
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

#ifdef _WIN32
    // Thiết lập bảng mã UTF-8 cho console trên Windows
    SetConsoleOutputCP(CP_UTF8);
#endif

    // In ra một vài ký tự Unicode
    std::wcout << L"Đây là một vài ký tự Unicode: " << std::endl;
    std::wcout << L"Chữ A có dấu sắc: Á" << std::endl;
    std::wcout << L"Chữ o có dấu ngã: õ" << std::endl;
    std::wcout << L"Chữ e có dấu huyền: è" << std::endl;

    // Bạn có thể thêm nhiều ký tự khác tại đây
    return 0;
}