#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool checkIs(TreeNode *root, TreeNode *&pre)
    {
        //check node isnt null terminal recursion
        if (root == NULL)
            return true;

        //vist left tree
        if (!checkIs(root->left, pre))
            return false;

        //root node
        if (pre != NULL && root->val <= pre->val)
            return false;
        pre = root;

        //riht tree
        return checkIs(root->right, pre);
    }
    bool isValidBST(TreeNode *root)
    {
        TreeNode *pre = NULL;
        return checkIs(root, pre);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode root(2);
    TreeNode left(5);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution s;
    //    s.isValidBST(&root);
    cout << s.isValidBST(&root) << endl;
    return 0;
}
