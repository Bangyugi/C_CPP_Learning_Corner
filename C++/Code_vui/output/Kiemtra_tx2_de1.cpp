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
        cout << endl;
    }
    void output()
    {
        cout << "\nName: " << name;
        cout << "\nGender: " << gender;
        cout << "\nYear of birth: " << birthYear;
        cout << endl;
    }
};
bool equal(giaoVien x, giaoVien y)
{
    return (strcmp(x.name, y.name)==0) && (strcmp(x.gender, y.gender)==0) && (x.birthYear == y.birthYear);
}

struct node
{
    giaoVien data;
    node *next;
    node(giaoVien x)
    {
        data = x;
        next = NULL;
    }
};

node *push_back(node *head, giaoVien x)
{
    if (head == NULL)
    {
        head = new node(x);
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node(x);
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        (temp->data).output();
        temp = temp->next;
    }
}

giaoVien SmallestBirthYear(node *head)
{
    giaoVien x;
    x.birthYear = 1e9;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.birthYear < x.birthYear)
        {
            x = temp->data;
        }
        temp = temp->next;
    }
    return x;
}

void displayMale(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (strcmp((temp->data).gender, "Nam") == 0)
            (temp->data).output();
        temp = temp->next;
    }
}

void deleteNode(node *head, giaoVien x)
{
    if (head == NULL)
    {
        cout << "\nList is empty!";
        return;
    }
    node *temp = head;
    bool check = false;
    while (temp->next != NULL)
    {
        if (equal(temp->next->data,x))
        {
            check = true;
            break;
        }
        temp = temp->next;
    }
    if (check)
    {
        node *erase = temp->next;
        temp->next = erase->next;
        delete erase;
        cout << "\nNode deleted!";
        cout << endl;
    }
    else
    {
        cout << "\nNot found!";
        cout << endl;
    }
}

node *insert(node *head, giaoVien x, int k)
{
    if (head == NULL)
    {
        return head;
    }
    node *temp = head;
    for (int i = 1; i <= k - 2;i++)
    {
        temp = temp->next;
    }
    node *newNode = new node(x);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        giaoVien x;
        x.input();
        head = push_back(head, x);
    }
    cout << "\nDanh sach sau khi tao: ";
    display(head);
    cout << "\nDanh sach giao vien nam: ";
    displayMale(head);
    cout << "\nNam sinh nho nhat: " << SmallestBirthYear(head).birthYear;
    deleteNode(head, SmallestBirthYear(head));
    cout << "\nDanh sach sau khi xoa: ";
    display(head);
    giaoVien x;
    cout << "\nNhap giao vien muon chen: \n";
    x.input();
    head = insert(head, x, 3);
    cout << "\nDanh sach sau khi chen: ";
    display(head);


    return 0;
}

// Nguyen Van A
// Nam
// 1982
// Tran Van B
// Nam
// 1975
// Phan Van C
// Nam
// 1977
// Nguyen Thi D
// Nu
// 1984
// Tran Thi E
// Nu
// 1982