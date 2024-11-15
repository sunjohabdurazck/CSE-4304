#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

enum Color { RED, BLACK };

struct TreeNode
{
    int value;
    Color color;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1), color(RED) {}
};

int getHeight(TreeNode* node)
{
    return node ? node->height : 0;
}

void updateHeight(TreeNode* node)
{
    if (node)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

TreeNode* rightRotate(TreeNode* y)
{
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

TreeNode* leftRotate(TreeNode* x)
{
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}
int getBalance(TreeNode* node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
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

    updateHeight(root);

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

void assignColors(TreeNode* root)
{
    if (!root) return;

    root->color = BLACK;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if (node->left)
        {
            node->left->color = (node->color == BLACK) ? RED : BLACK;
            q.push(node->left);
        }
        if (node->right)
        {
            node->right->color = (node->color == BLACK) ? RED : BLACK;
            q.push(node->right);
        }
    }
}

void printLevelOrder(TreeNode* root)
{
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        cout << "(" << node->value << "," << (node->color == BLACK ? "B" : "R") << ") ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main()
{

    int nodes[100];
    int i =0;

    while (i < 100)
    {
        cin >> nodes[i];
        if (cin.get() =='\n')
        {
            break;
        }
        i++;
    }

    TreeNode* avlRoot = nullptr;
    for (int j = 0; j <=i; j++)
    {
        avlRoot = insertAVL(avlRoot, nodes[j]);
    }

    assignColors(avlRoot);

    printLevelOrder(avlRoot);

    return 0;
}


int main()
{
    AVLTree avl;
    int key;
    while (true)
    {
        cin >> key;
        if (key == -1) break;
        avl.insertion(key);
    }
    return 0;
}
