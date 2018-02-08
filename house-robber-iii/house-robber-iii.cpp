/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <map>
#include <pair>


class Solution {
public:
    
    map< pair<TreeNode*, bool>, int > m;
    
    int real_rob(TreeNode* root, bool selected){
        if(!root){
            return 0;
        }
        pair<TreeNode*, bool> p(root,selected);
        
        if( m[p] ) return m[p];
        
        if(!selected){
            m[p] = max(real_rob(root->left, true)+real_rob(root->right, true) + root->val,  real_rob(root->left, false)+real_rob(root->right, false));
        }
        else
        {
            m[p] = real_rob(root->left, false)+real_rob(root->right, false);
        }
        return  m[p];
    }
    
    int rob(TreeNode* root) {
        return max(real_rob(root, true),real_rob(root, false));
    }
};
