#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isValid(char x, char y){
    return (x == '(' && y == ')' || x == '{' && y == '}' || x == '[' && y == ']');
}

bool checkParentheses(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            else if(!isValid(st.top(), s[i])) return false;
            else st.pop();
        }
    }
    return st.empty();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    cout << (checkParentheses(s) ? "YES" : "NO");
}