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

    bool solve(TreeNode* root, int i, int a, int fi, int fa)
    {
        if(!root) return true;
        if(fi && root->val <= i ) return false;
        if(fa && root->val >= a ) return false;
        return solve(root->left, fi?i:0, root->val, fi?i:0, 1) && solve(root->right, root->val, fa?a:0, 1, fa?a:0);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, 0, root->val, 0, 1) && solve(root->right, root->val, 1, 1, 0);
    }
};
