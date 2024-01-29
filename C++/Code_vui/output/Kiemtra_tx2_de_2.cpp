#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct giaoVien
{
    char name[30];
    char gender[5];
    int birthYear;

    void input()
    {
        cout << "Enter name: ";
        cin.getline(name, 30);
        cout << "Enter gender: ";
        cin.getline(gender, 5);
        cout << "Enter birth year: ";
        cin >> birthYear;
        cin.ignore();
    }

    void output()
    {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Birth year: " << birthYear << endl;
    }
};

struct nList
{
    int count;
    giaoVien e[10005];
};

void add(nList &L, giaoVien x)
{
    if (L.count == 10005 - 1)
    {
        return;
    }
    L.count++;
    L.e[L.count] = x;
}

void display(nList L)
{
    for (int i = 0; i <= L.count; i++)
    {
        L.e[i].output();
        cout << endl;
    }
}

void MaleDisplay(nList L)
{
    for (int i = 0; i <= L.count; i++)
    {
        if (strcmp(L.e[i].gender, "Nam") == 0)
        {
            L.e[i].output();
            cout << endl;
        }
    }
}

giaoVien SmallestBirthYear(nList L)
{
    giaoVien x;
    x.birthYear = 1e9;
    for (int i = 0; i <= L.count; i++)
    {
        if (L.e[i].birthYear<x.birthYear)
        {
            x = L.e[i];
        }
    }
    return x;
}

bool isEqual(giaoVien a, giaoVien b)
{
    return (strcmp(a.name, b.name) == 0) && (strcmp(a.gender, b.gender) == 0) && (a.birthYear == b.birthYear);
}

void remove(nList &L, giaoVien x)
{
    for (int i = 0; i <= L.count;i++)
    {
        if (isEqual(L.e[i],x))
        {
            for (int j = i; j <= L.count;j++)
            {
                L.e[j] = L.e[j + 1];
            }
            L.count--;
        }
    }
}

void insert (nList &L, giaoVien x, int k)
{
    L.count++;
    for (int i = L.count; i > k-1;i--)
    {
        L.e[i] = L.e[i - 1];
    }
    L.e[k - 1] = x;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    nList L;
    L.count = -1;
    for (int i = 0; i < 5; i++)
    {
        giaoVien x;
        x.input();
        add(L, x);
        cout << endl;
    }
    cout << "Danh sach sau khi tao: \n";
    display(L);
    cout << "Danh sach giao vien nam: \n";
    MaleDisplay(L);
    cout << "Nam sinh nho nhat la: " << SmallestBirthYear(L).birthYear << "\n\n";
    remove(L, SmallestBirthYear(L));
    cout << "Danh sach sau khi xoa la: \n";
    display(L);

    giaoVien x;
    x.input();
    insert(L, x, 3);
    cout << "Danh sach sau khi chen la: \n";
    display(L);

    return 0;
}
