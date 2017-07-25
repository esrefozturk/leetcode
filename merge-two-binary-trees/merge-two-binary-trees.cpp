/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        TreeNode *res = new TreeNode(0);
        TreeNode *t1Left = NULL;
        TreeNode *t1Right = NULL;
        TreeNode *t2Left = NULL;
        TreeNode *t2Right = NULL;
        if(t1)
        {
            res->val += t1->val;
            t1Left = t1->left;
            t1Right = t1->right;
        }
        if(t2)
        {
            res->val += t2->val;
            t2Left = t2->left;
            t2Right = t2->right;
        }
        res->left = mergeTrees(t1Left, t2Left);
        res->right = mergeTrees(t1Right, t2Right);
        return res;
    }
};
