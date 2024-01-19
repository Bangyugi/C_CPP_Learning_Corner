#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void makeNode(node *root, int v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeNode(root, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(node * root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    node *root=NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (root==NULL)
        {
            root = new node(x);
            makeNode(root, y, c);
        }
        else
        {
            insertNode(root, x, y, c);
        }
    }
    inorder(root);
    return 0;
}