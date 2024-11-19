#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        node *root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->left->right->right = new node(6);
        root->left->right->right->right = new node(7);

        Solution obj;
        int depth = obj.maxDepth(root);
        cout << "Maximum Depth of the Binary tree is : " << depth;
    }
    return 0;
}