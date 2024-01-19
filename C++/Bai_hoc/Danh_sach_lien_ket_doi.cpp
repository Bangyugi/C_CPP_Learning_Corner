#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *makeNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = newNode->prev = NULL;
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

int count(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}

void themDau(node *&head, int x)
{
    node *newNode = makeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void themCuoi(node *&head, int x)
{
    node *newNode = makeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void themGiua(node *&head, int x, int k)
{
    if (k == 1)
    {
        themDau(head, x);
        return;
    }
    if (k < 1 || k > count(head))
    {
        return;
    }
    node *newNode = makeNode(x);
    node *temp = head;
    for (int i = 1; i <= k - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void xoaDau(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

void xoaCuoi(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev == NULL)
    {
        delete temp;
        head = NULL;
        return;
    }
    temp->prev->next = NULL;
    delete temp;
}

void xoaGiua(node *&head, int k)
{
    if (k < 1 || k > count(head))
        return;
    if (k == 1)
    {
        xoaDau(head);
        return;
    }
    node *temp = head;
    for (int i = 1; i <= k - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else
    {
        temp->prev->next = NULL;
    }
    delete temp;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);

    // node *head = makeNode(10);
    // themDau(head, 20);
    // themCuoi(head, 30);
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    for (int i = 10; i <= 50; i += 10)
    {
        themCuoi(head1, i);
        themDau(head2, i);
    }
    themGiua(head1, 1000, 1);
    themGiua(head2, 1000, 3);
    themGiua(head3, 1000, 1);

    xoaDau(head2);
    xoaCuoi(head1);
    xoaGiua(head3, 1);
    // xoaGiua(head1, 1);
    // xoaGiua(head2, 5);

    duyet(head1);
    duyet(head2);
    duyet(head3);

    return 0;
}