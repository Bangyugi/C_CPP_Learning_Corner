#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct node
{
    int data;
    node *next;
};

node *makeNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int dem(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}

void themCuoi(node *&head, int x)
{
    node *temp = head;
    node *newNode = makeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void themDau(node *&head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void themGiua(node *&head, int x, int positon)
{
    node *newNode = makeNode(x);
    if (positon < 1 || positon > dem(head) + 1)
        return;
    if (positon==1)
    {
        themDau(head, x);
        return;
    }
    node *temp = head;
    for (int i = 1; i <= positon - 2;i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void xoaDau(node*&head)
{
    if (head == NULL)
        return;
    node *xoa = head;
    head = head->next;
    delete xoa;
}

void xoaCuoi(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    if (temp-> next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    node *xoa = temp->next;
    temp->next = NULL;
    delete xoa;
}

void xoaGiua(node *&head, int positon)
{
    if (positon<1 || positon>(dem(head)))
        return;
    if (positon==1)
    {
        xoaDau(head);
    }
    node *temp = head;
    for (int i = 1; i <= positon - 2;i++)
    {
        temp = temp->next;
    }
    node *xoa = temp->next;
    temp->next = xoa->next;
    delete xoa;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    node *head = makeNode(10);

    node *X = makeNode(20);
    head->next = X;

    node *Y = makeNode(30);
    X->next = Y;

    themCuoi(head, 40);

    for (int i = 1; i <= 5; i++)
    {
        themCuoi(head, i);
    }

    themDau(head, 50);

    themGiua(head, 60, 3);

    xoaDau(head);

    xoaCuoi(head);

    xoaGiua(head, 6);

    duyet(head);

    cout << dem(head) << endl;

    return 0;
}