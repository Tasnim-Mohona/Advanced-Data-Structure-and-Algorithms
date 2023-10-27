
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorderTraversal(TreeNode *root)
{
    if(root == NULL)
        return;

    stack<TreeNode*> treeStack;
    treeStack.push(root);

    while (!treeStack.empty())
    {
        TreeNode *currentNode = treeStack.top();
        cout << currentNode->data << " ";
        treeStack.pop();

        if(currentNode->right != NULL)
            treeStack.push(currentNode->right);
        if(currentNode->left != NULL)
            treeStack.push(currentNode->left);
    }
}







int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->left->left->right = new TreeNode('H');
    root->right = new TreeNode('C');
    root->right->left = new TreeNode('F');
    root->right->left->left = new TreeNode('I');
    root->right->left->right = new TreeNode('J');
    root->right->right = new TreeNode('G');

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

   //cout << "Postorder Traversal using one stack: ";
   // postorderTraversal(root);
    return 0;
}
