/*
MAXIMUM PATH SUM : 124
TOPIC - ARRAYS
LEVEL - HARD
SOURCE - STRIVER
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //first we need a different function to call for finding the sum
        int maxi = INT_MIN;

        maxPathDown(root,maxi);
        return maxi;
        
    }

    int maxPathDown(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }

        //we are taking zero as we do not want negative numbers to be there

        int left = max(0,maxPathDown(root->left,maxi));
        int right = max(0,maxPathDown(root->right,maxi));

        maxi = max(maxi, left + right + root->val);

        return max(left,right) + root->val;


    }




};
// @lc code=end

