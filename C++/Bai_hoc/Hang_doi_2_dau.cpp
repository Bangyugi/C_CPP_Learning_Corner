#include <bits/stdc++.h>
#include <deque>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

// stack: Last in firt out
// queue: Firt in firt out
// deque: double end queue

// size ()
// push_front(): day vao dau
// push_back(): day vao cuoi
// pop_front(): xoa dau
// pop_back(): xoa cuoi
// empty():
// fornt(): Lay ra phan tu o dau
// back(): lay ra phan tu o cuoi

int main()
{
    deque<int> Q;
    Q.push_front(2);
    Q.push_back(3);
    Q.push_front(4);
    Q.push_back(5);
    Q.push_front(1);
    for (auto x : Q)
    {
        cout << x << " ";
    }
    cout << endl;
    Q.pop_back();
    Q.pop_front();
    for (auto x : Q)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << Q.front() << " " << Q.back();
    return 0;
}