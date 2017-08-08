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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* t;
        if( nums.size() == 1 )
        {
            t = new TreeNode(nums[0]);
            return t;
        }
        int mindex = 0;
        int m = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if( m < nums[i] )
            {
                m = nums[i];
                mindex = i;
            }
        }
        t = new TreeNode(m);
        if( mindex != 0 )
        {
            vector<int> left(nums.begin(), nums.begin()+mindex);
             t->left = constructMaximumBinaryTree( left );
        }
        if( mindex+1 !=nums.size() )
        {
            vector<int> right(nums.begin()+mindex+1, nums.end());
            t->right = constructMaximumBinaryTree( right );
        }
        return t;
    }
};
