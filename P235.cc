/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //common binary tree
        //        if (root == NULL)
        //            return root;
        //        if (root == p || root == q)
        //            return root;
        //        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        //        if (left == NULL)
        //            return right;
        //        else if (right == NULL)
        //            return left;
        //        else
        //            return root;

        //BST recursion
        //if (root == NULL)
        //    return root;
        //if (p->val > root->val && q->val > root->val)
        //    return lowestCommonAncestor(root->right, p, q);
        //if (p->val < root->val && q->val < root->val)
        //    return lowestCommonAncestor(root->left, p, q);
        //return root;

        //BST loop
        TreeNode *tmp = root;
        while (tmp)
        {
            if (tmp->val > p->val && tmp->val > q->val)
                tmp = tmp->left;
            else if (tmp->val < p->val && tmp->val < q->val)
                tmp = tmp->right;
            else
                break;
        }
        return tmp;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode root(10);
    TreeNode left1(5);
    TreeNode left2(2);
    TreeNode right1(19);
    TreeNode right2(6);
    root.left = &left1;
    root.right = &right1;
    left1.left = &left2;
    left1.right = &right2;
    Solution s;
    cout << s.lowestCommonAncestor(&root, &left2, &right2)->val << endl;

    return 0;
}
