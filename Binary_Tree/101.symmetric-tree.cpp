/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

 //STRIVER SHEET FOR DSA
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricHelp(root->left,root->right); 
    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        if(left==NULL || right ==NULL){
            return left==right;
        }

        if(left->val!=right->val){
            return false;
        }
        return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right, right->left);
    }
};
// @lc code=end

