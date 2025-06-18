
/*
CHECK IF BINARY TREE IS BALANCED: Q-110
TOPIC - BINARY TREE
LEVEL - EASY
SOURCE - LEETCODE : STRIVER
*/
// @lc code=start

// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int heightfind (TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int lh = heightfind(node->left);
        int rh = heightfind(node->right);
        return 1+max(lh,rh);
    }


    bool isBalanced(TreeNode* root) {
        //firstly, we make a height finding function
        //now, if the tree is empty, Its a balanced binary tree.

        if(root==NULL){
            return true;
        }

        int left = heightfind(root->left);
        int right = heightfind(root->right);

        if(abs(left-right)<2 && isBalanced(root->left) && isBalanced (root->right)){
            return true;

        }

        return false;

        
    }
};
// @lc code=end

