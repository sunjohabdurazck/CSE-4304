#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

TreeNode* insertBST(TreeNode* root, int value)
{
    if (!root) return new TreeNode(value);
    if (value < root->value) root->left = insertBST(root->left, value);
    else root->right = insertBST(root->right, value);
    return root;
}

int getHeight(TreeNode* node)
{
    return node ? node->height : 0;
}

int getBalance(TreeNode* node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

TreeNode* rightRotate(TreeNode* y)
{
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

TreeNode* leftRotate(TreeNode* x)
{
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

TreeNode* insertAVL(TreeNode* root, int value)
{
    if (!root) return new TreeNode(value);

    if (value < root->value)
        root->left = insertAVL(root->left, value);
    else if (value > root->value)
        root->right = insertAVL(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->value)
        return rightRotate(root);

    if (balance < -1 && value > root->right->value)
        return leftRotate(root);

    if (balance > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int diameterOfTree(TreeNode* root, int& diameter)
{
    if (!root) return 0;

    int leftHeight = diameterOfTree(root->left, diameter);
    int rightHeight = diameterOfTree(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int calculateDiameter(TreeNode* root)
{
    int diameter = 0;
    diameterOfTree(root, diameter);
    return diameter;
}

int main()
{
    int n;
    cin >> n;

    int nodes[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    TreeNode* bstRoot = nullptr;
    for (int i = 0; i < n; i++)
    {
        bstRoot = insertBST(bstRoot, nodes[i]);
    }
    int bstDiameter = calculateDiameter(bstRoot);

    TreeNode* avlRoot = nullptr;
    for (int i = 0; i < n; i++)
    {
        avlRoot = insertAVL(avlRoot, nodes[i]);
    }
    int avlDiameter = calculateDiameter(avlRoot);

    cout << "BST = " << bstDiameter << endl;
    cout << "AVL = " << avlDiameter << endl;
    cout << "Difference = " << (bstDiameter - avlDiameter) << endl;

    return 0;
}

