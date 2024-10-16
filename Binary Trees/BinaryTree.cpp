#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the data for Inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the data for the root node :";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left data for node" << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        };

        cout << "Enter the right data for node" << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void preOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inorderTree(Node *root, int cnt)
{
    if (root == NULL)
        return;
    inorderTree(root->left, cnt);
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    };
    inorderTree(root->right, cnt);
}

int nofoLeafNodes(Node *root)
{
    int cnt = 0;
    inorderTree(root, cnt);
    return cnt;
}
int main()
{

    Node *root = NULL;

    // creating Tree
    // root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    // build tree from level order

    buildFromLevelOrder(root);

    // level order traversal
    cout << "Level Order Traversal " << endl;
    levelOrderTraversal(root);

    cout << "No of Lead Nodes in a Tree : " << nofoLeafNodes(root) << endl;
    cout << "Preorder Tree Traversal " << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder Tree Traversal " << endl;
    inOrder(root);
    cout << endl;
    cout << "PostOrder Tree Traversal  " << endl;
    postOrder(root);
    cout << endl;
    return 0;
}