#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct Good
{
    int id;
    char tenHang[30];
    char tenNhaSanXuat[30];
    int namSanXuat;
    int giaBan;

    Good(int id){
        this.id = id
    }
};

void input(Good &x)
{
    cout << "Nhap id: ";
    cin >> x.id;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    cin.getline(x.tenHang, 30);
    cout << "Nhap ten nha san xuat: ";
    cin.getline(x.tenNhaSanXuat, 30);
    cout << "Nhap nam san xuat: ";
    cin >> x.namSanXuat;
    cout << "Nhap gia ban: ";
    cin >> x.giaBan;
    cin.ignore();
}

void output(Good x)
{
    cout << "Id: " << x.id << endl;
    cout << "Ten san pham: " << x.tenHang << endl;
    cout << "Ten nha san xuat: " << x.tenNhaSanXuat << endl;
    cout << "Nam san xuat: " << x.namSanXuat << endl;
    cout << "Gia ban: " << x.giaBan << endl;
    cout << endl;
}

struct node
{
    Good data;
    node *next;
};

node *makeNode(Good x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}


void themCuoi(node *&head, Good x)
{
    if (head == NULL)
    {
        head = makeNode(x);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = makeNode(x);
}

int size(node *head)
{
    int res = 0;
    node *temp = head;
    while (temp != NULL)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
void themGiua(node *&head, Good x, int k)
{
    if (k < 1 || k > size(head) + 1)
        return;
    if (k == 1)
    {
        node *newNode = makeNode(x);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i <= k - 2; i++)
        {
            temp = temp->next;
        }
        node *newNode = makeNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void xoaGiua(node *&head, int k)
{
    if (k < 1 || k > size(head) + 1)
        return;
    if (k == 1)
    {
        node *eraseNode = head;
        head = eraseNode->next;
        delete eraseNode;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i <= k - 2; i++)
        {
            temp = temp->next;
        }
        node *eraseNode = temp->next;
        temp->next = eraseNode->next;
        delete eraseNode;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        output(temp->data);
        temp = temp->next;
    }
}
void delete1998(node *&head)
{
    node *prev = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.namSanXuat == 1998)
        {
            if (prev == NULL)
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }

    }
}

int main()
{
    node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        Good x;
        input(x);
        themCuoi(head, x);
    }
    display(head);
    // cout << "Nhap node: \n";
    // Good x;
    // input(x);
    // int k;
    // cout << "Nhap vi tri muon chen: ";
    // cin >> k;
    // cin.ignore();
    // themGiua(head, x, k);
    // display(head);
    // cout << "Nhap vi tri muon xoa: ";
    // cin >> k;
    // xoaGiua(head, k);
    // display(head);
    delete1998(head);
    display(head);
    return 0;
}

// 10002
// iPad Pro
// Apple
// 1998
// 3000000

// 10003
// iPad Mini
// Apple
// 2022
// 1500000

// 10004
// iPad (9th generation)
// Apple
// 1998
// 2000000

// 10005
// iPad Air (5th generation)
// Apple
// 1998
// 2500000

// 10006
// iPad Pro (6th generation)
// Apple
// 2025
// 3500000

// 10007
// iPad Pro (7th generation)
// Apple
// 1998
// 4000000