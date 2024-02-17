#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct Car
{
    int maximumCapacity;
    char id[10];
    int numberOfPassenger = 0;
    void input()
    {
        cout << "Enter car's id: ";
        cin >> id;
        cout << "Enter maximum capacity: ";
        cin >> maximumCapacity;
        cout << "Enter number of passengers in car: ";
        cin >> numberOfPassenger;
        // Tớ cho luôn number of passenger vào đây để tiện cho việc truy xuất và kiểm tra
        // Cho chắc cú tớ bắt lỗi numberOfPassenger > maximumCapacity
        while (true)
        {
            if (numberOfPassenger > maximumCapacity)
            {
                cout << "Number of passenger should be less than maximum capacity.\nEnter again: ";
                cin >> numberOfPassenger;
            }
            else
            {
                break;
            }
        }
    }
    void output()
    {
        cout << "ID: " << id << endl;
        cout << "Maximum capacity: " << maximumCapacity << endl;
        cout << "Number of passenger: " << numberOfPassenger << endl;
    }
};

struct node
{
    Car data;
    node *next;
    node(Car x)
    {
        data = x;
        next = NULL;
    }
};

void push_font(node *&head, Car x)
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
}

void removeEmpty(node *&head)
{
    // Tớ kiểm tra nếu phần tử đầu tiên có số hành khách == 0 thì xóa. 
    // Note: Tớ dùng while để xóa đến khi phần tử head là null hoặc !=0
    while (head != NULL && head->data.numberOfPassenger == 0)
    {
        node *eraseNode = head;
        head = head->next;
        delete eraseNode;
    }

    // Sau khi xử lý trường hợp phần tử đầu == 0 thì có 2 trường hợp xảy ra 1 là head == NULL và head != NULL
    // Head == NULL -> return
    if (head == NULL)
        return;

    //  Trường hợp head != NULL thì thực hiện hàm xóa như tớ code dưới đây
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data.numberOfPassenger == 0)
        {
            node *eraseNode = temp->next;
            temp->next = eraseNode->next;
            delete eraseNode;
        }
        else
        {
            temp = temp->next;
        }
    }
}

int length(node *head)
{
    int result = 0;
    node *temp = head;
    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }
    return result;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp->data.output();
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    while (true)
    {
        cout << "----------------------------------------------\n";
        cout << "1. Add more car to the railroad train\n";
        cout << "2. Remove all empty cars in the railroad train\n";
        cout << "3. Display all cars of the railroad train\n";
        cout << "4. Display length of the railroad train\n";
        cout << "0. Exit\n";
        cout << "----------------------------------------------\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            Car car;
            car.input();
            push_font(head, car);
            break;
        }
        case 2:
        {
            removeEmpty(head);
            break;
        }
        case 3:
        {
            display(head);
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Length of the railroad train: " << length(head) << endl;
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
            break;
        }
    }
    return 0;
}

// C0005
// 20
// 0
// C0004
// 20
// 10
// C0003
// 20
// 17
// C0002
// 20
// 0
// C0001
// 20
// 0

// C0005
// 20
// 0
// C0004
// 20
// 0
// C0003
// 20
// 0
// C0002
// 20
// 0
// C0001
// 20
// 0