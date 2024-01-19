#include <bits/stdc++.h>
#include <deque>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
 
// priority_queue
/// push
// size
// empty
// pop
// top

int main()
{
    priority_queue<int, vector<int>, greater<>>pQ;
    pQ.push(1);
    pQ.push(2);
    pQ.push(3);
    pQ.push(4);
    pQ.push(5);
    cout<<pQ.top()<<endl;
    pQ.push(100);
    pQ.push(30);
    cout<<pQ.top()<<endl;
    pQ.pop();
    cout<<pQ.top()<<endl;


    return 0;
}