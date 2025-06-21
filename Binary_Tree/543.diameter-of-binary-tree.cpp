/*
DIAMETER OF BINARY TREE : Q-542
TOPIC - BINARY TREE
LEVEL - MEDIUM
SOURCE - LEETCODE : STRIVER
*/
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

    //finding height
    int findheight(TreeNode* node,int& maxi){
        if(node==NULL){
            return 0;
        }

        int lh = findheight(node->left,maxi);
        int rh = findheight(node->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        findheight(root,dia);
        return dia;


    }
};
// @lc code=end

