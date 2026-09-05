#include <iostream>
using namespace std;
#include <queue>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void PreOrder(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void LevelOrderTraversal(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i =0;i < size ; i++)
        {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if(temp->right != nullptr)
        {
            q.push(temp->right);
        }
        } 
        cout << endl;
    }
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(6);
    root->left->right = createNode(5);
    root->right->right = createNode(7);

    cout << "\nPreOrder Traversal .... " << endl;
    PreOrder(root);
    
    cout << "\nInOrder Traversal ...." << endl;
    InOrder(root);

    cout << "\nPostOrder Traversal ...." << endl;
    PostOrder(root);

    cout << "\nLevel Order Traveral ...." << endl;
    LevelOrderTraversal(root);
    return 0;
}
