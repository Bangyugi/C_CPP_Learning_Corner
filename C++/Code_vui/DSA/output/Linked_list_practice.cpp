#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node *pushfront(node *&head, int x)
{
    if (head == NULL)
    {
        head = new node(x);
    }
    else
    {
        node *newNode = new node(x);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

node *init(node *head, int n)
{
    while (n)
    {
        head = pushfront(head, n % 10);
        n /= 10;
    }
    return head;
}

void display(node *head)
{
    node *temp = head->next;
    if (head->data == -1)
    {
        cout << "-";
    }
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int size(node *head)
{
    node *temp = head->next;
    int res = 0;
    while (temp != NULL)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
int sumDigits(node *head)
{
    node *temp = head->next;
    int res = 0;
    while (temp != NULL)
    {
        res+=temp->data;
        temp = temp->next;
    }
    return res;
}

node *insert(node *head, int x, int k)
{
    if (head == NULL)
    {
        cout << "ERROR: List is empty!" << endl;
        return head;
    }
    if (k < 1 || k > size(head) + 1)
    {
        cout << "ERROR: Index k out of bound!" << endl;
        return head;
    }
    if (k == 1)
    {
        node *newNode = new node(x);
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        node *temp = head->next;
        for (int i = 1; i <= k - 2; i++)
        {
            temp = temp->next;
        }
        node *newNode = new node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "Added!" << endl;
    return head;
}

node *remove(node *head, int k)
{
    if (head == NULL)
    {
        cout << "ERROR: List is empty!" << endl;
        return head;
    }
    if (k < 1 || k > size(head))
    {
        cout << "ERROR: Index k out of bound!" << endl;
        return head;
    }
    if (k == 1)
    {
        node *temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    else
    {
        node *temp = head->next;
        for (int i = 1; i <= k - 2;i++)
        {
            temp = temp->next;
        }
        node *eraseNode = temp->next;
        temp->next = eraseNode->next;
        delete eraseNode;
    }
    cout << "Removed!" << endl;
    return head;
}

int main()
{
    int integer;
    cout << "Enter an interger: ";
    cin >> integer;
    node *head = NULL;
    head = init(head, abs(integer));
    if (integer < 0)
    {
        head = pushfront(head, -1);
    }
    else
    {
        head = pushfront(head, 1);
    }
    display(head);
    while (true)
    {
        // system("cls");
        cout << "------------------------- MENU ------------------------------" << endl;
        cout << "(1) add new digits at position k in an integer\n";
        cout << "(2) remove a digit at position k in an integer\n";
        cout << "(3) calculate the sum of all digits from an unbounded integer\n";
        cout << "(4) display the whole number on the screen\n";
        cout << "(5) Exit\n";
        cout << "-------------------------------------------------------------\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x, k;
            cout << "Enter a digit: ";
            cin >> x;
            cout << "Enter position: ";
            cin >> k;
            head = insert(head, x, k);
            break;
        }
        case 2:
        {
            int k;
            cout << "Enter position: ";
            cin >> k;
            head = remove(head, k);
            break;
        }
        case 3:
        {
            cout << "sum of all digits equal to " << sumDigits(head)<<endl;
            break;
        }
        case 4:
        {
            display(head);
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }

    return 0;
}