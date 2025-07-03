/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
vector<int>vec;
int level=0;

    void checker(TreeNode * node, int level){
        if(node==NULL){
            return ;
        }
        //check if the level is same as the vector size
        if(level==vec.size()){
            vec.push_back(node->val);
        }
        //now we go to rightside first
        checker(node->right,level+1);
        checker(node->left,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        //firstly we need a data structure to keep track of elements.
        
        //now we need to call another function which access the globally available stack.
        checker(root,level);
        return vec;
    }
};
// @lc code=end

