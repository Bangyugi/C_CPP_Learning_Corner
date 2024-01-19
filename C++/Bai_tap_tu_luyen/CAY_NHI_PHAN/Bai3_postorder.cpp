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

void postorder(node * root)
{
    if (root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root== NULL)
        {
            root = new node(u);
            makeNode(root, v, c);
        }
        else
        {
            insertNode(root, u, v, c);
        }
    }

    postorder(root);
    return 0;
}

